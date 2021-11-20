#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* thread_run(void* arg) {
    while (1) {
        printf("I'm child!\n");
    }

    return (void*) 0;
}

int main(int argc, char** argv) {
    pthread_t thread;

    if (pthread_create(&thread, NULL, thread_run, NULL)) {
        printf("Error while creating a thread\n");
        return 1;
    }

    usleep(2000);

    if (pthread_cancel(thread)) {
        printf("Error while cancelling a thread\n");
        return 1;
    }

    if (pthread_join(thread, NULL)) {
        printf("Error joining thread \n");
        return 1;
    }

    printf("Done fine\n");

    return 0;
}
