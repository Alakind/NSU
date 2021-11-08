#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define NUM_MUTEXES 3

pthread_mutex_t mutexes[3];
int initialized = 0;

void* child_run() {
    int cur_mutex = 0;

    pthread_mutex_lock(&mutexes[cur_mutex]);
    initialized = 1;

    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutexes[(cur_mutex + 1) % 3]);

        char* child_massage = "I'm child!---------\n";
        write(1, child_massage, strlen(child_massage));

        pthread_mutex_unlock(&mutexes[cur_mutex]);

        cur_mutex = (cur_mutex + 1) % 3;
    }

    return (void*) 0;
}

void* main_run() {
    int cur_mutex = 1;
    while (!initialized);

    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutexes[(cur_mutex + 1) % 3]);

        char* child_massage = "I'm main!\n";
        write(1, child_massage, strlen(child_massage));

        pthread_mutex_unlock(&mutexes[cur_mutex]);

        cur_mutex = (cur_mutex + 1) % 3;
    }


    return (void*) 0;
}

int main() {
    pthread_t child_thread;

    pthread_mutexattr_t mutex_attributes;
    pthread_mutexattr_init(&mutex_attributes);
    pthread_mutexattr_settype(&mutex_attributes, PTHREAD_MUTEX_ERRORCHECK);

    for (int i = 0; i < NUM_MUTEXES; i++) {
        pthread_mutex_init(&mutexes[i], &mutex_attributes);
    }
    pthread_mutexattr_destroy(&mutex_attributes);

    pthread_mutex_lock(&mutexes[1]);

    if (pthread_create(&child_thread, NULL, child_run, NULL) != 0) {
        for (int i = 0; i < NUM_MUTEXES; i++) {
            pthread_mutex_destroy(&mutexes[i]);
        }

        return 1;
    }

    main_run();

    if (pthread_join(child_thread, NULL) != 0) {
        for (int i = 0; i < NUM_MUTEXES; i++) {
            pthread_mutex_destroy(&mutexes[i]);
        }

        return 1;
    }

    return 0;
}
