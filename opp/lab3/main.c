#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <mpi/mpi.h>

int main(int argc, char** argv) {
    // SETTING UP
    MPI_Init(&argc, &argv);
    int proc_num;
    MPI_Comm_size(MPI_COMM_WORLD, &proc_num);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Input
    printf("Enter n1, n2, n3\n");
    int n1;
    int n2;
    int n3;
    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);

    double* A_matrix = (double*)malloc(n1 * n2);
    double* B_matrix = (double*)malloc(n3 * n2);

    printf("Enter p1\n");
    int p1;
    int p2;
    scanf("%d", &p1);
    p2 = proc_num / p1;

    // Paralleling
    double* hold_matrix = (double*)malloc(p1 * sizeof(double));
    MPI_Scatter(A_matrix, p1, MPI_DOUBLE, hold_matrix, p1, MPI_DOUBLE, 0, MPI_COMM_WORLD);



    free(A_matrix);
    free(B_matrix);
    return 0;
}
