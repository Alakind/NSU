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

    

    return 0;
}
