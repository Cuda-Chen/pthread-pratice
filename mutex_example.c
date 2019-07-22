#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int counter = 0;

void *child() {
    for(int i = 0; i < 3; i++) {
        int temp = counter;
        sleep(1);
        counter = temp + 1;
        printf("Counter = %d\n", counter);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, child, NULL);
    pthread_create(&t2, NULL, child, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
