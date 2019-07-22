#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *child(void *arg) {
    int *input = (int *)arg;
    int *result = malloc(1 * sizeof(int));
    result[0] = input[0] + input[1];
    pthread_exit((void *)result);
}

int main() {
    pthread_t t;
    void *ret;
    int input[2] = {1, 3};

    pthread_create(&t, NULL, child, (void *)input);

    pthread_join(t, &ret);

    int *result = (int *)ret;

    printf("%d + %d = %d\n", input[0], input[1], result[0]);

    free(result);

    return 0;
}
