#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum = 0; // Shared data

void *runner(void *parameters) {
    int i, upper = *(int *)parameters;
    int *sum = (int *)malloc(sizeof(int)); 
    *sum = 0;

    if (upper >= 0) {
        for (i = 0; i <= upper; i++) {
            *sum += i;
        }
    }

    pthread_exit((void *)sum); 
}


int main(int argc, char *argv[]) {
    pthread_t threadID; // Thread identifier
    pthread_attr_t attributes; // Thread attributes
    int num;

    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    pthread_attr_init(&attributes); // Initialize thread attributes

    pthread_create(&threadID, &attributes, runner, (void *)&num); // Create thread
    /*The fourth argument (void *)&num is passing the address of num to the runner function.
    Inside runner, we retrieve it with:
    int upper = *(int *)parameters;
    This converts the void* pointer back to an int*, then dereferences it to get the actual value.
    This method allows pthread_create to send data to the thread function. */   

    pthread_join(threadID, NULL); // Wait for thread to complete


    printf("Sum = %d\n", sum);
    return 0;
}
