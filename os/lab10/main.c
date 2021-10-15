#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define PHILO 5
#define DELAY 100
#define FOOD 1000

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

void drop_fork(int fork) {
    pthread_mutex_unlock(&forks[fork]);
}

int food_on_table(int eat) {
  static int food = FOOD;
  int myfood;

  pthread_mutex_lock(&foodlock);

  if (food > 0 && eat) {
    food--;
  }
  myfood = food;

  pthread_mutex_unlock(&foodlock);

  return myfood;
}

void* philosopher(void* phil_id) {
    int id = *((int*) phil_id);

    int left_fork = id;
    int right_fork = (id + 1) % PHILO;

    int food_left;

    while (food_left = food_on_table(0)) {

        take_fork(id, left_fork, "left");
        //try_take_fork(id, right_fork, "right");
        if (!try_take_fork(id, right_fork, "right")) {
            //drop_forks(left_fork, right_fork);
            drop_fork(left_fork);
            usleep(DELAY);
            continue;
        }

        food_on_table(1);

        printf("Philosopher %d eats dish with %d\n", id, food_left);
        drop_forks(left_fork, right_fork);

        eaten[id] += 1;

        usleep(DELAY);
    }

    return (void*) 0;
}

int main(int argc, char** argv) {
    pthread_mutex_init(&foodlock, NULL);

    int indexes[] = {0, 1, 2, 3, 4};

    for (int i = 0; i < PHILO; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }
    for (int i = 0; i < PHILO; i++) {
        pthread_create(&phils[i], NULL, philosopher, (void*) &indexes[i]);
    }

    for (int i = 0; i < PHILO; i++) {
        pthread_join(phils[i], NULL);
    }

    for (int i = 0; i < PHILO; i++) {
        printf("\nPhilosother %d ate %d\n", i + 1, eaten[i]);
    }

    return 0;
}
