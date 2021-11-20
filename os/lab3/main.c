#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void* thread_run(void* arg) {
    char** strings = (char**) arg;

    for (; *strings != NULL; strings++) {
        printf("%s\n", *strings);
    }

    return (void*) 0;
}

int main(int argc, char** argv) {

    pthread_t threads[4];

    char* arg1[2] = { "arg1-1", NULL };
    char* arg2[3] = { "arg2-1", "arg2-2", NULL };
    char* arg3[4] = { "arg3-1", "arg3-2", "arg3-3", NULL };
    char* arg4[5] = { "arg4-1", "arg4-2", "arg4-3", "arg4-4", NULL };
    char** args[4] = { arg1, arg2, arg3, arg4 };

    for (int i = 0; i < 4; i++) {
        if (pthread_create(&threads[i], NULL, thread_run, args[i])) {
            printf("Error creating thread %d\n", i + 1);
            return 1;
        }    
    }

    for (int i = 0; i < 4; i++) {
        if (pthread_join(threads[i], NULL)) {
            printf("Error joining thread %d\n", i + 1);
            return 1;
        }
    }

    return 0;
}
