#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <mpi.h>


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
    return 6 - 100000 * phi(x, y, z);
}

int fill_matrix(float* matrix, int Nx, int Ny, int Nz, int rank, int proc_num) {
    for (int i = 0; i < Nx; i++) {
        for (int j = 0; j < Ny; j++) {
            for (int k = 0; k < Nz / proc_num; k++) {
                if (i == 0 || j == 0 || i == Nx - 1 || j == Ny - 1) {
                    matrix[i * Nx * Ny + j * Ny + k] = phi(Nx, Ny, Nz, i, j, k);
                }
                else if ((k == 0 && rank == 0) || ((k == Nz / proc_num - 1) && rank == proc_num - 1)) {
                    matrix[i * Nx * Ny + j * Ny + k] = phi(Nx, Ny, Nz, i, j, k);
                }
                else {
                    matrix[i * Nx * Ny + j * Ny + k] = 0;
                }
            }
        }
    }
}

int send_jacobi(int Nx, int Ny, int Nz, int rank, int proc_num) {
    if (rank != proc_num - 1) {
        MPI_Isend();
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
    double matrix[Nx * Ny * (Nz / proc_num)];

    fill_matrix(matrix, Nx, Ny, Nz, rank, proc_num);

    while (/* NOT FINISHED */) {
        // SEND_DATA

        // COUNT CENTER

        // RECIEVE DATA

        // COUNT EDGE
    }

    return 0;
}
