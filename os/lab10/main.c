#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define PHILO 5
#define DELAY 3000
#define FOOD 100

static int food = FOOD;

pthread_mutex_t forks[PHILO];
pthread_mutex_t foodlock;
pthread_t phils[PHILO];
int eaten[PHILO];

void take_fork(int phil, int fork, char* hand) {
    pthread_mutex_lock(&forks[fork]);
    printf("Philosopher %d: got %d fork to his %s hand\n",
        phil, fork, hand);
}

void drop_forks(int left_fork, int right_fork) {
    pthread_mutex_unlock(&forks[left_fork]);
    pthread_mutex_unlock(&forks[right_fork]);
}

void eat_food(int philosopher, int part_to_eat) {
    pthread_mutex_lock(&foodlock);

    food =- part_to_eat;

    eaten[philosopher] += part_to_eat;
    printf("Philosopher %d has eaten %d food\n",
        philosopher, part_to_eat);
    printf("Food left: %d\n", food);

    usleep(DELAY);
    
    pthread_mutex_unlock(&foodlock);
}

void* philosopher(void* phil_id) {
    int id = (int) phil_id;

    int left_fork = id;
    int right_fork = id + 1;

    while (food > 0) {
        if (id == 0 || id == 2) {
            take_fork(id, left_fork, "left");
            take_fork(id, right_fork, "right");

            eat_food(id, 10);

            drop_forks(left_fork, right_fork);
            usleep(DELAY * 2);
        } else if (id == 1 || id == 3) {
            usleep(DELAY);

            take_fork(id, left_fork, "left");
            take_fork(id, right_fork, "right");

            eat_food(id, 10);

            drop_forks(left_fork, right_fork);
        } else {
            usleep(DELAY * 2);

            take_fork(id, left_fork, "left");
            take_fork(id, right_fork, "right");

            eat_food(id, 10);

            drop_forks(left_fork, right_fork);
        }
    }
}

int main(int argc, char** argv) {
    pthread_mutex_init(&foodlock, NULL);

    for (int i = 0; i < PHILO; i++) {
        pthread_mutex_init(&forks[i], NULL);
        pthread_create(&phils[i], NULL, philosopher, (void*) i);
    }

    for (int i = 0; i < PHILO; i++) {
        pthread_join(phils[i], NULL);
    }
}
