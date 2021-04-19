#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <mpi/mpi.h>

double rand_double(double min, double max) {
    return min + (rand() / (RAND_MAX / (max - min)));
}

void make_random_matrix(double* matrix, int n1, int n2) {
    for (int i = 0; i < n1; i++) {
        for (int j = i; j < n2; j++) {
            matrix[i*n1 + j] = rand_double(0, 1);
            if (i == j) {
                matrix[i*n1 + j] += 1000;
            }
            else {
                matrix[j*n1 + i] = matrix[i*n1 + j];
            }
        }
    }
}

double mul_matrix_line_pillar(double* first_matrix, double* second_matrix, int raw, int column, int n2, int n3) {
    double result = 0;

    for (int i = 0; i < n2; i++) {
        result += first_matrix[raw * n2 + i] * second_matrix[i * n3 + column];
    }

    return result;
}

MPI_Comm grid_comm;
MPI_Comm col_comm;
MPI_Comm row_comm;

int grid[2];

int n1 = 4;
int n2 = 4;
int n3 = 4;
int p1 = 2;
int p2 = 2;

int main(int argc, char** argv) {
    // SETTING UP
    MPI_Init(&argc, &argv);
    int proc_num;
    MPI_Comm_size(MPI_COMM_WORLD, &proc_num);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Creating grid
    int dim[2];
    dim[0] = p1;
    dim[1] = p2;

    MPI_Cart_create(MPI_COMM_WORLD, 2, dim, 0, 0, &grid_comm);
    MPI_Cart_coords(grid_comm, rank, 2, grid);

    int dimen[2];
    dimen[0] = 0;
    dimen[1] = 1;
    MPI_Cart_sub(grid_comm, dimen, &row_comm);

    dimen[0] = 1;
    dimen[1] = 0;
    MPI_Cart_sub(grid_comm, dimen, &col_comm);

    // Creating matrixes
    double* A_matrix = (double*)malloc(n1 * n2 * sizeof(double));
    double* B_matrix = (double*)malloc(n3 * n2 * sizeof(double));
    double* C_matrix = (double*)malloc(n1 * n3 * sizeof(double));

    printf("Runnung on %d total\n", proc_num);

    // Generating matrixies
    make_random_matrix(A_matrix, n1, n2);
    make_random_matrix(B_matrix, n2, n3);

    int height = n1 / p1;
    int width = n3 / p2;

    double* A_hold_matrix = (double*)malloc(height * n2 * sizeof(double));
    double* B_hold_matrix = (double*)malloc(width * n2 * sizeof(double));

    // Datatype
    MPI_Datatype col;
    MPI_Type_vector(p1, width, n3, MPI_DOUBLE, &col); // first n2?
    MPI_Type_commit(&col);

    // Scattering and broadcasting
    if (grid[1] == 0) {
        MPI_Scatter(A_matrix, height * n2, MPI_DOUBLE, A_hold_matrix, height * n2, MPI_DOUBLE, 0, col_comm);
    }

    Bcast(A_hold_matrix, height * n2, MPI_DOUBLE, 0, row_comm);

    if (grid[0] == 0) {
        MPI_Scatter(B_matrix, 1, col, B_hold_matrix, width * n2, MPI_DOUBLE, 0, row_comm);
    }

    // Paralleling
    /*double* hold_A_matrix = (double*)malloc(height * n2 * sizeof(double));
    MPI_Scatter(A_matrix, height * n2, MPI_DOUBLE, hold_A_matrix, height * n2, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    double* hold_B_matrix = (double*)malloc(width * n2 * sizeof(double));
    MPI_Scatter(B_matrix, width * n2, col, hold_B_matrix, width * n2, col, 0, MPI_COMM_WORLD);

    // Action
    for (int i = (rank % p2) * height; i < (rank % p2) * (height + 1); i++) {
        for (int j = (rank / p2) * width; j < (rank / p2) * (width + 1); j++) {
            C_matrix[i * n3 + j] = mul_matrix_line_pillar(A_matrix, B_matrix, i, j, n2, n3);
        }
    }*/

    // Finishing
    MPI_Finalize();

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n3; j++) {
            printf("%lf ", C_matrix[i * n3 + j]);
        }
        printf("\n");
    }

    free(A_matrix);
    free(B_matrix);
    free(C_matrix);
    free(hold_A_matrix);
    free(hold_B_matrix);
    return 0;
}
