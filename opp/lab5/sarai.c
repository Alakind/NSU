#include <stdio.h>
#include "mpi.h"
#include <pthread.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#define N 2
#define iters 4
#define startWeight 10
#define REQUEST_TAG 10
#define ANSWER_TAG 20
#define SUCCESS 500
#define FAIL 404
#define NEED_TASKS 220
#define TURN_OFF 312

int sizeMx[] = {5, 3, 1};
typedef struct taskList {
	int weights[40];
	int size;
	int curTask;
} taskList;

taskList list;
int ping, size, rank, curIter, *arrOfProc;
MPI_Datatype MPI_TASKLIST;
pthread_mutex_t taskMutex;

void refreshList() {
	printf("Refreshing task list for %d\n", rank);
	pthread_mutex_lock(&taskMutex);
	list.size = 8;

	for (int i = 0; i < list.size; i++){
		list.weights[i] = startWeight + (startWeight / 4) * (rank + 1); 
	}
	list.curTask = 0;
	pthread_mutex_unlock(&taskMutex);
}

void createNewList(){
	printf("Creating new task list for %d\n", rank);
	list.size = 8;
	pthread_mutex_lock(&taskMutex);
	for (int i = 0; i < list.size; i++){
		//list.weights[i] = startWeight + (startWeight / 4) * (rank + 1); 
	}

	list.curTask = 0;
	pthread_mutex_unlock(&taskMutex);
}

int getTask(int from){
	pthread_mutex_lock(&taskMutex);
	ping = NEED_TASKS;
	pthread_mutex_unlock(&taskMutex);
	printf("Need tasks from %d to %d\n", from, rank);
	sleep(2);	
	MPI_Send(&ping, 1, MPI_INT, from, REQUEST_TAG, MPI_COMM_WORLD);
    MPI_Recv(&ping, 1, MPI_INT, from, ANSWER_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    sleep(2);
    if (ping == FAIL){
    	printf("Proc %d can't take task from %d\n", rank, from);
    	return FAIL;
    }

    printf("Getting tasks for me (%d) from %d\n", rank, from);
    pthread_mutex_lock(&taskMutex);
    MPI_Recv(&list, 1, MPI_TASKLIST, from, ANSWER_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    pthread_mutex_unlock(&taskMutex);

    return SUCCESS;
}

void *doTask(void *args){
	unsigned long long int t;
	arrOfProc = (int*) malloc (sizeof(int) * size);
	for (int i = 0; i < size; i++){
		arrOfProc[i] = (i == rank? 0 : 1);
	}

	//starting iterations

	while (curIter < iters){

		pthread_mutex_lock(&taskMutex);

		while (list.curTask < list.size){
			printf("Doing task %d of %d with weight %d for proc %d\n", list.curTask+1, list.size, list.weights[list.curTask], rank);
			int task = list.weights[list.curTask];
			pthread_mutex_unlock(&taskMutex);
			for (unsigned long long int i = 0; i < task; i++){
				t = (i / 100) * (i / 100);
			}
			pthread_mutex_lock(&taskMutex);
			list.curTask++;
		}

		pthread_mutex_unlock(&taskMutex);
		printf("Tasks done for %d.\n", rank);
		int flag = 0;

		for (int i = 0; i < size; i++){
			if (arrOfProc[i]){
				if (getTask(i) == SUCCESS){
					flag = 1;
					break;
				}
				else {
					arrOfProc[i] = 0;
				}
			}
		}

		if (flag == 1) {
			printf("I got task for %d!\n", rank);
			continue;
		}
		printf("End of iterations for %d\n", rank);
		MPI_Barrier(MPI_COMM_WORLD);

		refreshList();
		pthread_mutex_lock(&taskMutex);
		curIter++;

		pthread_mutex_unlock(&taskMutex);
		for (int i = 0; i < size; i++){
			arrOfProc[i] = (i==rank? 0 : 1);
		}
	}

	printf("Proc %d done his work\n", rank);
	pthread_mutex_lock(&taskMutex);
    ping = TURN_OFF;
    pthread_mutex_unlock(&taskMutex);
    MPI_Send(&ping, 1, MPI_INT, rank, REQUEST_TAG, MPI_COMM_WORLD);
    return NULL;
}

void *taskSendThread(void *args){
	while (curIter < iters) {
		MPI_Status status;
        MPI_Recv (&ping, 1, MPI_INT, MPI_ANY_SOURCE, REQUEST_TAG, MPI_COMM_WORLD, &status);
        //sleep(2);
        if (ping == TURN_OFF){
        	printf("Turn off proc %d\n", rank);
        	break;
        }
        pthread_mutex_lock(&taskMutex);
        printf("Sending tasks from %d to %d\n", rank, status.MPI_SOURCE);
        if (list.curTask >= list.size - 1) {
        	printf("Proc %d haven't tasks for send\n", rank);
        	pthread_mutex_unlock(&taskMutex);
        	ping = FAIL;
        	MPI_Send(&ping, 1, MPI_INT, status.MPI_SOURCE, ANSWER_TAG, MPI_COMM_WORLD);
            continue;
        }
        else {
        	list.size--;
        	pthread_mutex_unlock(&taskMutex);
        	taskList newList;
        	newList.size = 1;
        	newList.curTask = 0;
        	newList.weights[0] = list.weights[list.size];
        	ping = SUCCESS;
        	MPI_Send(&ping, 1, MPI_INT, status.MPI_SOURCE, ANSWER_TAG, MPI_COMM_WORLD);
            MPI_Send(&newList, 1, MPI_TASKLIST, status.MPI_SOURCE, ANSWER_TAG, MPI_COMM_WORLD);
            continue;
        }
	}
	printf("Tasks thread from %d done successfully\n", rank);
	return NULL;
}

void typeCreate() {
	const int num = 3;
	int lenOfBlocks[] = {1, 1, 1};
	MPI_Datatype types[] = {MPI_INT, MPI_INT, MPI_INT};
    MPI_Aint offsets[3];

    offsets[0] = offsetof(taskList, weights);
    offsets[1] = offsetof(taskList, size);
    offsets[2] = offsetof(taskList, curTask);

    MPI_Type_create_struct(num, lenOfBlocks, offsets, types, &MPI_TASKLIST);
    MPI_Type_commit(&MPI_TASKLIST);
}

int main(int argc, char** argv){
	int prov;
	MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &prov);
    if (prov != MPI_THREAD_MULTIPLE) {
        printf("%d \n", prov);
        MPI_Finalize();
        return 1;
    }

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    typeCreate();
    createNewList();
    pthread_mutex_init(&taskMutex, NULL);

    pthread_attr_t attrs;
    if (0 != pthread_attr_init(&attrs)){
    	perror("Can't init atributes");
    	abort();
    }
    if (0 != pthread_attr_setdetachstate (&attrs, PTHREAD_CREATE_JOINABLE)){
    	perror("Can't set atributes");
    	abort();
    }

    pthread_t threads[2];
    pthread_create(&threads[0], &attrs, taskSendThread, NULL);
    pthread_create(&threads[1], &attrs, doTask, NULL);
    pthread_attr_destroy(&attrs);
    for (int i = 0; i < 2; i++){
    	if (0 != pthread_join(threads[i], NULL)){
    		perror("Can't join a thread");
    		abort();
    	}
    }

    pthread_mutex_destroy(&taskMutex);
    
    MPI_Finalize();
    return 0;
}
