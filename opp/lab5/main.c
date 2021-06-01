#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <mpi.h>
//#include "mpi.h"

#define L 100
#define TASK_SETS 3
#define REQUEST 1
#define ANSWER 2
#define SUCCESS 100
#define FAILURE 101
#define ASKFORTASKS 200
#define FINISH 300

int proc_num;
int rank;

pthread_mutex_t my_mutex;
long long* jobs;
int iteration = 0;
int iterations_total = 5;
int cur_task = 0;
int num_of_tasks;

void make_job_list(int rank, int proc_num);

int ask_for_task(int who) {
    int buf = ASKFORTASKS;

    // requesting
    MPI_Send(&buf, 1, MPI_INT, who, REQUEST, MPI_COMM_WORLD);
    MPI_Recv(&buf, 1, MPI_INT, who, ANSWER, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    int job_got;
    if (buf == FAILURE) {
        //printf("Can't ask\n");
        return 0;
    }
    else {
        MPI_Recv(&job_got, 1, MPI_INT, who, ANSWER, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    //printf("Finished asking\n");
    return job_got;
}

void* task_doer(void* a) {
    while (iteration < iterations_total) {
        if (rank == 0) {
            printf("------------------\n");
        }
        double start = MPI_Wtime();
        // Making up tasks
        pthread_mutex_lock(&my_mutex);
        make_job_list(rank, proc_num);

        // Doing tasks
        while (cur_task < num_of_tasks) {
            int difficulty = jobs[cur_task];
            pthread_mutex_unlock(&my_mutex);
            for (long long i = 0; i < difficulty; i++) {
                int result = sqrt(cos(i));
            }
            pthread_mutex_lock(&my_mutex);
            cur_task++;
        }
        pthread_mutex_unlock(&my_mutex);

        //printf("I'm %d go ask\n", rank);
        // Finished, asking for tasks from others
        int job;
        for (int i = 0; i < proc_num; i++) {
            if (i != rank) {
                if ((job = ask_for_task(i)) != 0) {
                    pthread_mutex_lock(&my_mutex);
                    jobs[cur_task] = job;
                    num_of_tasks++;
                    pthread_mutex_unlock(&my_mutex);
                    continue;
                }
            }
        }

        double finish = MPI_Wtime();
        printf("Time for proc %d of iteration %d: %lf\n", rank, iteration, finish - start);

        MPI_Barrier(MPI_COMM_WORLD);

        iteration++;
    }

    //printf("Finishing proccess doer\n");
    int buf = FINISH;
    MPI_Send(&buf, 1, MPI_INT, rank, REQUEST, MPI_COMM_WORLD);
    

    return NULL;
}

void* task_sender(void* a) {
    //printf("I am task sender!\n");
    MPI_Status status;
    int buf;

    while(iteration < iterations_total) {
        MPI_Recv(&buf, 1, MPI_INT, MPI_ANY_SOURCE, REQUEST, MPI_COMM_WORLD, &status);

        if (buf == FINISH) {
            //printf("Finishing proccess sender\n");
            return NULL;
        }

        pthread_mutex_lock(&my_mutex);
        
        if (buf == ASKFORTASKS) {
            if (cur_task = num_of_tasks - 1) {
                //printf("No tasks to share\n");
                pthread_mutex_unlock(&my_mutex);
                buf = FAILURE;
                MPI_Send(&buf, 1, MPI_INT, status.MPI_SOURCE, ANSWER, MPI_COMM_WORLD);
            }
            else {
                printf("Sending task\n");
                num_of_tasks--;
                pthread_mutex_unlock(&my_mutex);
                buf = SUCCESS;
                int new_task = jobs[num_of_tasks];
                MPI_Send(&buf, 1, MPI_INT, status.MPI_SOURCE, ANSWER, MPI_COMM_WORLD);
                MPI_Send(&new_task, 1, MPI_INT, status.MPI_SOURCE, ANSWER, MPI_COMM_WORLD);
            }
        }
    }

    printf("Task sender finished successfully\n");
    return NULL;
}

void make_job_list(int rank, int proc_num) {
    num_of_tasks = 100 * proc_num;
    cur_task = 0;

    for (int i = 0; i < num_of_tasks; i++) {
        //jobs[i] = (long long)(abs(50 - i %100) * abs(rank - (iteration % proc_num)) * L);
        jobs[i] = (long long)abs(rank + pow(7, iteration) * L);
    }

    return;
}


int main(int argc, char** argv) {
    // SETTING UP
    int provided;
    MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &provided);
    MPI_Comm_size(MPI_COMM_WORLD, &proc_num);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    num_of_tasks = 100 * proc_num;
    jobs = (long long*)malloc(num_of_tasks * sizeof(long long));

    if (provided != MPI_THREAD_MULTIPLE) {
        printf("MPI can't get us requirements\n");
        MPI_Finalize();
        return 1;
    }

    // Creating mutex
    pthread_mutex_init(&my_mutex, NULL);
    pthread_attr_t attributes;
    pthread_t thread;

    int retval = pthread_attr_init(&attributes);
    if (retval != 0) {
        printf("Can't init attributes\n");
        return 1;
    }
    retval = pthread_attr_setdetachstate(&attributes, PTHREAD_CREATE_JOINABLE);
    if (retval != 0) {
        printf("Can't set attributes\n");
        return 1;
    }

    // Starting division
    pthread_create(&thread, &attributes, task_sender, NULL);
    task_doer(NULL);

    pthread_attr_destroy(&attributes);

    pthread_join(thread, NULL);

    pthread_mutex_destroy(&my_mutex);
    

    MPI_Finalize();
    free(jobs);

    return 0;
}
