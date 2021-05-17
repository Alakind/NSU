#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <mpi.h>

MPI_Request send_request[2];
MPI_Request recieve_request[2];

int old_matrix = 0;
int new_matrix = 1;

double a = 100000;

double get_coordinates(int proc_amount, int coord) {
    return -1 + coord * (2 / (proc_amount));
}

double phi(int Nx, int Ny, int Nz, double x, double y, double z) {
    int coord_x = get_coordinates(Nx, x);
    int coord_y = get_coordinates(Ny, y);
    int coord_z = get_coordinates(Nz, z);

    return coord_x * coord_x + coord_y * coord_y + coord_z * coord_z;
}

double right_part(double x, double y, double z) {
    return 6 - a * phi(x, y, z);
}

int fill_matrix(float* matrix, int Nx, int Ny, int Nz, int rank, int proc_num) {
    for (int i = 0; i < Nx; i++) {
        for (int j = 0; j < Ny; j++) {
            for (int k = 0; k < Nz / proc_num; k++) {
                if (i == 0 || j == 0 || i == Nx - 1 || j == Ny - 1) {
                    matrix[0][i * Nx * Ny + j * Ny + k] = phi(Nx, Ny, Nz, i, j, k);
                    matrix[1][i * Nx * Ny + j * Ny + k] = phi(Nx, Ny, Nz, i, j, k);
                }
                else if ((k == 0 && rank == 0) || ((k == Nz / proc_num - 1) && rank == proc_num - 1)) {
                    matrix[0][i * Nx * Ny + j * Ny + k] = phi(Nx, Ny, Nz, i, j, k);
                    matrix[1][i * Nx * Ny + j * Ny + k] = phi(Nx, Ny, Nz, i, j, k);
                }
                else {
                    matrix[0][i * Nx * Ny + j * Ny + k] = 0;
                    matrix[1][i * Nx * Ny + j * Ny + k] = 0;
                }
            }
        }
    }
}

int send_recv_jacobi(double* send_matrix, double* recv_matrix, int Nx, int Ny, int Nz, int rank, int proc_num) {
    if (rank != proc_num - 1) {
        MPI_Isend(send_matrix, Nx * Ny, MPI_DOUBLE, rank + 1, 1, MPI_COMM_WORLD, &send_request[1]);
        MPI_Irecv(recv_matrix[1], Nx * Ny, MPI_DOUBLE, rank + 1, 0, MPI_COMM_WORLD, &recieve_request[1]);
    }
    if (rank != 0) {
        MPI_Isend(send_matrix, Nx * Ny, MPI_DOUBLE, rank - 1, 1, MPI_COMM_WORLD, &send_request[0]);
        MPI_Irecv(recv_matrix[0], Nx * Ny, MPI_DOUBLE, rank - 1, 0, MPI_COMM_WORLD, &recieve_request[1]);
    }
}

int count_center(double* matrix, int Nx, int Ny, int Nz) {
    double hx = 2 / (Nx - 1);
    double hy = 2 / (Ny - 1);
    double hz = 2 / (Nz - 1);

    for (int i = 0; i < Nx; i++) {
        for (int j = 0; j < Ny; j++) {
            for (int k = 0; k < Nz / proc_num; k++) {
                matrix[i * Nx * Ny + j * Ny + k] = ((matrix) / (hx * hx) + ) / 
                                                    (2 / (hx * hx) + 2 / (hy * hy) + 2 / (hz * hz) + a);
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

    int Nx = 1000;
    int Ny = 1000;
    int Nz = 1000;
    double matrix[2][Nx * Ny * (Nz / proc_num)];

    fill_matrix(matrix, Nx, Ny, Nz, rank, proc_num);

    //while (/* NOT FINISHED */) {
        // SEND_RECIEVE_DATA (send_recv_jacobi)

        // COUNT CENTER (count_center)

        // WAIT

        // COUNT EDGE
    //}

    return 0;
}
