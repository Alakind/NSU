#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t semaphore1;
sem_t semaphore2;

void* thread_child_run(void* arg) {
    for (int i = 0; i < 10; i++) {
        sem_wait(&semaphore1);

        printf("I'm child -------------\n");

        sem_post(&semaphore2);
    }

    return (void*) 0;
}

void* thread_parent_run(void* arg) {
    for (int i = 0; i < 10; i++) {
        sem_wait(&semaphore2);

        printf("I'm parent\n");

        sem_post(&semaphore1);
    }

    return (void*) 0;
}

int main() {
    if (sem_init(&semaphore1, 0, 0) == -1) {
        printf("Error creating first semaphore\n");
        return 1;
    }
    if (sem_init(&semaphore2, 0, 1) == -1) {
        printf("Error creating second semaphore\n");
        return 1;
    }

    pthread_t thread;
    if (pthread_create(&thread, NULL, thread_child_run, NULL)) {
        printf("Error creating thread\n");
        return 1;
    }

    thread_parent_run(NULL);

    if (pthread_join(thread, NULL)) {
        printf("Error joining thread\n");
        return 1;
    }

    sem_destroy(&semaphore1);
    sem_destroy(&semaphore2);

    return 0;
}
