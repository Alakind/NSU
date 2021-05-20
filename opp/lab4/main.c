#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <mpi.h>

MPI_Request send_request[2];
MPI_Request recieve_request[2];

int old = 0;
int new = 1;

double a = 100000;
double epsilon = 0.00000001;

double get_coordinates(int proc_amount, int coord) {
    return -1 + coord * (2 / (proc_amount));
}

double phi(int Nx, int Ny, int Nz, double x, double y, double z) {
    int coord_x = get_coordinates(Nx, x);
    int coord_y = get_coordinates(Ny, y);
    int coord_z = get_coordinates(Nz, z);

    return coord_x * coord_x + coord_y * coord_y + coord_z * coord_z;
}

double right_part(int Nx, int Ny, int Nz, double x, double y, double z) {
    return 6 - a * phi(Nx, Ny, Nz, x, y, z);
}

int fill_matrix(double** matrix, int Nx, int Ny, int Nz, int rank, int proc_num) {
    for (int i = 0; i < Nz; i++) {
        for (int j = 0; j < Ny; j++) {
            for (int k = 0; k < Nx; k++) {
                if (k == 0 || j == 0 || k == Nx - 1 || j == Ny - 1) {
                    matrix[0][i * Nx * Ny + j * Nx + k] = phi(Nx, Ny, Nz, i, j, k);
                    matrix[1][i * Nx * Ny + j * Nx + k] = phi(Nx, Ny, Nz, i, j, k);
                }
                else if ((i == 0 && rank == 0) || ((i == Nz / proc_num - 1) && rank == proc_num - 1)) {
                    matrix[0][i * Nx * Ny + j * Nx + k] = phi(Nx, Ny, Nz, i, j, k);
                    matrix[1][i * Nx * Ny + j * Nx + k] = phi(Nx, Ny, Nz, i, j, k);
                }
                else {
                    matrix[0][i * Nx * Ny + j * Nx + k] = 0;
                    matrix[1][i * Nx * Ny + j * Nx + k] = 0;
                }
            }
        }
    }
}

void send_recv_jacobi(double** send_matrix, double** recv_matrix, int Nx, int Ny, int Nz, int rank, int proc_num) {
    if (rank != proc_num - 1) {
        MPI_Isend(send_matrix[old], Nx * Ny, MPI_DOUBLE, rank + 1, 1, MPI_COMM_WORLD, &send_request[1]);
        MPI_Irecv(recv_matrix[1], Nx * Ny, MPI_DOUBLE, rank + 1, 0, MPI_COMM_WORLD, &recieve_request[0]);
    }
    if (rank != 0) {
        MPI_Isend(send_matrix[old], Nx * Ny, MPI_DOUBLE, rank - 1, 0, MPI_COMM_WORLD, &send_request[0]);
        MPI_Irecv(recv_matrix[0], Nx * Ny, MPI_DOUBLE, rank - 1, 1, MPI_COMM_WORLD, &recieve_request[1]);
    }
}

void count_center(double** matrix, int Nx, int Ny, int Nz, int* keep_calc, int rank, int proc_num) {
    double hx = 2 / (Nx - 1);
    double hy = 2 / (Ny - 1);
    double hz = 2 / (Nz - 1);

    for (int i = 1; i < Nz - 1; i++) {
        for (int j = 1; j < Ny - 1; j++) {
            for (int k = 1; k < Nx - 1; k++) {
                matrix[new][i * Nx * Ny + j * Ny + k] = ((matrix[old][(i - 1) * Nx * Ny + j * Nx + k] + matrix[old][(i + 1) * Nx * Ny + j * Nx + k]) / (hx * hx) 
                                                     + (matrix[old][i * Nx * Ny + (j + 1) * Nx + k] + matrix[old][i * Nx * Ny + (j - 1) * Nx + k]) / (hy * hy)
                                                     + (matrix[old][i * Nx * Ny + j * Nx + k + 1] + matrix[old][i * Nx * Ny + j * Nx + k - 1]) / (hz * hz)
                                                     - right_part(Nx, Ny, Nz, i, j, k)) / 
                                                    (2 / (hx * hx) + 2 / (hy * hy) +
                                                     2 / (hz * hz) + a);
                if (abs(matrix[new][i * Nx * Ny + j * Nx + k] - matrix[old][i * Nx * Ny + j * Nx + k]) > epsilon) {
                    *keep_calc = 1;
                }
            }
        }
    }

}

void wait_data(int rank, int proc_num) {
    if (rank != proc_num - 1) {
        MPI_Wait(&send_request[1], MPI_STATUS_IGNORE);
        MPI_Wait(&recieve_request[0], MPI_STATUS_IGNORE);
    }
    if (rank != 0) {
        MPI_Wait(&send_request[0], MPI_STATUS_IGNORE);
        MPI_Wait(&recieve_request[1], MPI_STATUS_IGNORE);
    }
}

void count_edges(double** matrix, double** recv_matrix, int Nx, int Ny, int Nz, int* keep_calc, int rank, int proc_num) {
    double hx = 2 / (Nx - 1);
    double hy = 2 / (Ny - 1);
    double hz = 2 / (Nz - 1);

    if (rank != proc_num - 1) {
        int i = proc_num - 1;
        for (int j = 1; j < Ny - 1; j++) {
            for (int k = 1; k < Nx - 1; k++) {
                matrix[new][i * Nx * Ny + j * Ny + k] = ((matrix[old][(i - 1) * Nx * Ny + j * Nx + k] + recv_matrix[1][j * Ny + k]) / (hx * hx) 
                                                        + (matrix[old][i * Nx * Ny + (j + 1) * Nx + k] + matrix[old][i * Nx * Ny + (j - 1) * Nx + k]) / (hy * hy)
                                                        + (matrix[old][i * Nx * Ny + j * Nx + k + 1] + matrix[old][i * Nx * Ny + j * Nx + k - 1]) / (hz * hz)
                                                        - right_part(Nx, Ny, Nz, i, j, k)) / 
                                                        (2 / (hx * hx) + 2 / (hy * hy) +
                                                        2 / (hz * hz) + a);
                if (abs(matrix[new][i * Nx * Ny + j * Nx + k] - matrix[old][i * Nx * Ny + j * Nx + k]) > epsilon) {
                    *keep_calc = 1;
                }
            }
        }
    }
    if (rank != 0) {
        int i = 0;
        for (int j = 1; j < Ny - 1; j++) {
            for (int k = 1; k < Nx - 1; k++) {
                matrix[new][i * Nx * Ny + j * Nx + k] = ((recv_matrix[0][i * Nx * Ny + j * Nx + k] + matrix[old][(i + 1) * Nx * Ny + j * Nx + k]) / (hx * hx) 
                                                        + (matrix[old][i * Nx * Ny + (j + 1) * Nx + k] + matrix[old][i * Nx * Ny + (j - 1) * Nx + k]) / (hy * hy)
                                                        + (matrix[old][i * Nx * Ny + j * Nx + k + 1] + matrix[old][i * Nx * Ny + j * Nx + k - 1]) / (hz * hz)
                                                        - right_part(Nx, Ny, Nz, i, j, k)) / 
                                                        (2 / (hx * hx) + 2 / (hy * hy) +
                                                        2 / (hz * hz) + a);
                if (abs(matrix[new][i * Nx * Ny + j * Nx + k] - matrix[old][i * Nx * Ny + j * Nx + k]) > epsilon) {
                    *keep_calc = 1;
                }
            }
        }
    }
    
}

int main(int argc, char** argv) {
    // SETTING UP
    MPI_Init(&argc, &argv);
    int proc_num;
    MPI_Comm_size(MPI_COMM_WORLD, &proc_num);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int Nx = 480;
    int Ny = 480;
    int Nz = 480 / proc_num;
    double** matrix = (double**)malloc(2 * sizeof(double*));
    double** rec_matrix = (double**)malloc(2 * sizeof(double*));
    for (int i = 0; i < 2; i++) {
        matrix[i] = (double*)malloc(Nx * Ny * Nz * sizeof(double));
        rec_matrix[i] = (double*)malloc(Nx * Ny * Nz * sizeof(double));
    }

    fill_matrix(matrix, Nx, Ny, Nz, rank, proc_num);

    double start = MPI_Wtime();

    int keep_calc = 1;
    while (keep_calc) {
        keep_calc = 0;
        // sending and recieving data
        send_recv_jacobi(matrix, rec_matrix, Nx, Ny, Nz, rank, proc_num);

        // calculating middle values
        count_center(matrix, Nx, Ny, Nz, &keep_calc, rank, proc_num);

        // waiting for data
        wait_data(rank, proc_num);

        // calculating edge values
        count_edges(matrix, rec_matrix, Nx, Ny, Nz, &keep_calc, rank, proc_num);

        old = 1 - old;
        new = 1 - new;

        int keep_calc_tmp;
        MPI_Allreduce(&keep_calc, &keep_calc_tmp, 1, MPI_INT, MPI_MAX, MPI_COMM_WORLD);
        keep_calc = keep_calc_tmp;
    }

    double finish = MPI_Wtime();
    if (rank == 0) {
        printf("Time taken: %lf\n", finish - start);
    }

    for (int i = 0; i < 2; i++) {
        free(matrix[i]);
        free(rec_matrix[i]);
    }
    free(matrix);
    free(rec_matrix);

    MPI_Finalize();
    return 0;
}
