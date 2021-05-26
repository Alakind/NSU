#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <mpi.h>

#define L 100
#define TASK_SETS 3

pthread_mutex_t my_mutex;
int* jobs

int* make_job_list(int rank, int proc_num, int iteration) {
    int* jobs = (int*)malloc(100 * proc_num * sizof(int));

    if (!jobs) {
        return NULL;
    }

    for (int i = 0; i < proc_num * 100; i++) {
        jobs[i] = abs(50 - i %100) * abs(rank - (iteration % proc_num)) * L;
    }

    return jobs;
}

int do_the_work() {

}

int main(int argc, char** argv) {
    // SETTING UP
    int provided;
    MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &provided);
    int proc_num;
    MPI_Comm_size(MPI_COMM_WORLD, &proc_num);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int iteration = 0;

    if (provided != MPI_THREAD_MULTIPLE) {
        printf("MPI can't get us requirements\n");
        MPI_Finalize();
        return 1;
    }

    // Creating mutex
    pthread_mutex_init(&my_mutex, NULL);

    for (int i = 0; i < TASK_SETS; i++) {
        // Init job list
        jobs = make_job_list(rank, proc_num, iteration);



        free(jobs);
    }


    pthread_mutex_destroy(&my_mutex);

    MPI_Finalize();

    return 0;
}
