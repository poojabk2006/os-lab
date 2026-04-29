#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

pthread_mutex_t chopstick[N];

void* philosopher(void* num) {
    int id = *(int*)num;

    do {
        printf("Philosopher %d is thinking\n", id);
        sleep(1);
        if (id == N - 1) {
            pthread_mutex_lock(&chopstick[(id + 1) % N]);
            printf("Philosopher %d picked right chopstick\n", id);

            pthread_mutex_lock(&chopstick[id]);
            printf("Philosopher %d picked left chopstick\n", id);
        } else {
            pthread_mutex_lock(&chopstick[id]);
            printf("Philosopher %d picked left chopstick\n", id);

            pthread_mutex_lock(&chopstick[(id + 1) % N]);
            printf("Philosopher %d picked right chopstick\n", id);
        }


        printf("Philosopher %d is eating\n", id);
        sleep(1);


        pthread_mutex_unlock(&chopstick[id]);
        pthread_mutex_unlock(&chopstick[(id + 1) % N]);

        printf("Philosopher %d put down chopsticks\n", id);

    } while (1);

    return NULL;
}

int main() {
    pthread_t thread[N];
    int ids[N];

    for (int i = 0; i < N; i++) {
        pthread_mutex_init(&chopstick[i], NULL);
    }


    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&thread[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(thread[i], NULL);
    }

    return 0;
}

