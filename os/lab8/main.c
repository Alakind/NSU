#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int threads_number = 1;
int iterations = 10000000;

struct args {
    long int thread_number;
    double result_part;
} typedef args;

void* count_part(void* arg) {
    double pi = 0;

    for (int i = ((args*)arg)->thread_number; i < iterations; i += threads_number) {
        pi += 1.0 / (i * 4.0 + 1.0);
        pi -= 1.0 / (i * 4.0 + 3.0);
    }

    ((args*)arg)->result_part = pi;

    return arg;
}

int main(int argc, char** argv) {

    if (argc > 1) {
        threads_number = atoi(argv[1]);
    }

    clock_t start = clock();

    pthread_t* threads = malloc(threads_number * sizeof(pthread_t));
    args* arguments = malloc(threads_number * sizeof(args));

    for (int i = 0; i < threads_number; i++) {
        arguments[i].thread_number = i;

        if (pthread_create(&(threads[i]), NULL, count_part, (void*)&arguments[i])) {
            printf("Error when creating thread\n");

            return 0;
        }
    }

    double pi = 0;

    for (int i = 0; i < threads_number; i++) {
        pthread_join(threads[i], NULL);

        pi += arguments[i].result_part;
    }

    pi *= 4;

    printf("Number is %lf\n", pi);

    clock_t finish = clock();

    printf("Time taken %ld\n", finish - start);

    free(threads);
    free(arguments);

    return 0;
}
