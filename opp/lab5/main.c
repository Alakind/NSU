#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <mpi.h>

#define L 100
#define TASK_SETS 3
#define REQUEST 1
#define ANSWER 2
#define SUCCESS 100
#define FAILURE 101
#define ASKFORTASKS 200
#define FINISH 201

int proc_num;
int rank;

pthread_mutex_t my_mutex;
int* jobs;
int iteration = 0;
int iterations_total = 0;
int cur_task = 0;
int num_of_tasks;

void task_doer() {
    
}

void task_sender(void) {
    MPI_Status status;
    int buf;

    while(iteration < iterations_total) {
        MPI_Recv(&buf, 1, MPI_INT, MPI_ANY_SOURCE, REQUEST, MPI_COMM_WORLD, &status);

        if (buf = FINISH) {
            printf("Finishing proccess\n");
            return;
        }

        pthread_mutex_lock(&my_mutex);
        
        if (cur_task = num_of_tasks - 1) {
            printf("No tasks to share\n");
            pthread_mutex_unlock(&my_mutex);
            buf = FAILURE;
            MPI_Send(&ping, 1, MPI_INT, status.MPI_SOURCE, ANSWER, MPI_COMM_WORLD);
        }
        else {
            num_of_tasks--;
            pthread_mutex_unlock(&my_mutex);
            buf = SUCCESS;
            int new_task = jobs[num_of_tasks];
            MPI_Send(&ping, 1, MPI_INT, status.MPI_SOURCE, ANSWER, MPI_COMM_WORLD);
            MPI_Send(&new_task, 1, MPI_INT, status.MPI_SOURCE, ANSWER, MPI_COMM_WORLD);
        }
    }

    printf("Task sender finished successfully\n");
    return;
}

int* make_job_list(int rank, int proc_num, int iteration, int num_of_tasks) {
    num_of_tasks = 100 * proc_num;
    int* jobs = (int*)malloc(num_of_tasks * sizof(int));
    cur_task = 0;

    if (!jobs) {
        return NULL;
    }

    for (int i = 0; i < num_of_tasks; i++) {
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
    MPI_Comm_size(MPI_COMM_WORLD, &proc_num);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    num_of_tasks = 100 * proc_num;

    if (provided != MPI_THREAD_MULTIPLE) {
        printf("MPI can't get us requirements\n");
        MPI_Finalize();
        return 1;
    }

    // Creating mutex
    pthread_mutex_init(&my_mutex, NULL);

    for (int i = 0; i < TASK_SETS; i++) {
        // Init job list
        jobs = make_job_list(rank, proc_num, iteration, num_of_tasks);



        free(jobs);
    }


    pthread_mutex_destroy(&my_mutex);

    MPI_Finalize();

    return 0;
}
