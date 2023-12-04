#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

sem_t x, y;
pthread_t writerthreads[100], readerthreads[100];
int readercount = 0;

void *reader(void *param) {
    sem_wait(&x);
    readercount++;
    if (readercount == 1)
        sem_wait(&y);
    sem_post(&x);
    printf("%lu Reader is inside\n", pthread_self());
    usleep(100000); // Simulating reader reading time
    sem_wait(&x);
    readercount--;
    if (readercount == 0) {
        sem_post(&y);
    }
    sem_post(&x);
    printf("%lu Reader is leaving\n", pthread_self());
    return NULL;
}

void *writer(void *param) {
    sem_wait(&y);
    printf("%lu Writer is inside\n", pthread_self());
    usleep(100000); // Simulating writer writing time
    sem_post(&y);
    printf("%lu Writer is leaving\n", pthread_self());
    return NULL;
}

int main() {
    int n2, i;
    printf("Enter the number of readers and writers: ");
    scanf("%d", &n2);
    printf("\n");
    sem_init(&x, 0, 1);
    sem_init(&y, 0, 1);
    for (i = 0; i < n2; i++) {
        pthread_create(&readerthreads[i], NULL, reader, NULL);
        pthread_create(&writerthreads[i], NULL, writer, NULL);
    }
    for (i = 0; i < n2; i++) {
        pthread_join(readerthreads[i], NULL);
        pthread_join(writerthreads[i], NULL);
    }
    return 0;
}
