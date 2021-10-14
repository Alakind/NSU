#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define PHILO 5
#define DELAY 3000
#define FOOD 100

pthread_mutex_t forks[PHILO];
pthread_mutex_t foodlock;
pthread_t phils[PHILO];
int eaten[PHILO];

void take_fork(int phil, int fork, char* hand) {
    pthread_mutex_lock(&forks[fork]);
    printf("Philosopher %d: got %d fork to his %s hand\n",
        phil, fork, hand);
}

int try_take_fork(int phil, int fork, char* hand) {
    if (pthread_mutex_trylock(&forks[fork])) {
        printf("Philosopher %d: got %d fork to his %s hand\n",
            phil, fork, hand);
        return 1;
    } else {
        return 0;
    }
}

void drop_forks(int left_fork, int right_fork) {
    pthread_mutex_unlock(&forks[left_fork]);
    pthread_mutex_unlock(&forks[right_fork]);
}

void* philosopher(void* phil_id) {
    int id = (int) phil_id;

    int left_fork = id;
    int right_fork = id + 1;

    int food_left = -100;

    while (food_left = food_on_table()) {

        take_fork(id, left_fork, "left");
        try_take_fork(id, right_fork, "right");
        // if (!try_take_fork(id, right_fork, "right")) {
        //     drop_forks(left_fork, right_fork);
        //     food_return();
        //     continue;
        // }

        printf("Philosopher %d eats dish with %d\n", id, food_left);
        drop_forks(left_fork, right_fork);

        usleep(DELAY);

        eaten[id] += 1;
    }

    return (void*) 0;
}

int food_on_table() {
  static int food = FOOD;
  int myfood;

  pthread_mutex_lock(&foodlock);

  if (food > 0) {
    food--;
  }
  myfood = food;

  pthread_mutex_unlock(&foodlock);

  return myfood;
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

    for (int i = 0; i < PHILO; i++) {
        printf("\nPhilosother %d ate %d\n", i + 1, eaten[i]);
    }

    return 0;
}
