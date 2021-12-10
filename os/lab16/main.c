#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <semaphore.h>

sem_t* semaphore1;
sem_t* semaphore2;
const char* name1 = "semaphore1";
const char* name2 = "semaphore2";

void* thread_child_run(void* arg) {
    semaphore1 = sem_open(name1, O_CREAT, 0777, 0);
    if (semaphore1 == SEM_FAILED) {
        printf("Error openong semaphore\n");
        return (void*) 1;
    }
    semaphore2 = sem_open(name2, O_CREAT, 0777, 1);
    if (semaphore2 == SEM_FAILED) {
        printf("Error openong semaphore\n");
        return (void*) 1;
    }

    for (int i = 0; i < 10; i++) {
        sem_wait(semaphore1);

        printf("I'm child -------------\n");

        sem_post(semaphore2);
    }

    sem_close(semaphore1);
    sem_close(semaphore2);

    return (void*) 0;
}

void* thread_parent_run(void* arg) {
    semaphore1 = sem_open(name1, O_CREAT, 0777, 0);
    if (semaphore1 == SEM_FAILED) {
        printf("Error openong semaphore\n");
        return (void*) 1;
    }
    semaphore2 = sem_open(name2, O_CREAT, 0777, 1);
    if (semaphore2 == SEM_FAILED) {
        printf("Error openong semaphore\n");
        return (void*) 1;
    }

    for (int i = 0; i < 10; i++) {
        sem_wait(semaphore2);

        printf("I'm parent\n");

        sem_post(semaphore1);
    }

    sem_close(semaphore1);
    sem_close(semaphore2);

    return (void*) 0;
}

int main() {

    pid_t pid = fork();

    if (pid == 0) {
        thread_parent_run(NULL);
    } else {
        thread_child_run(NULL);
        sem_unlink(name1);
        sem_unlink(name2);
    }



    return 0;
}
