#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 10

typedef struct {
    int *array;
    int start;
    int end;
} SortParams;

void *sort_half(void *arg) {
    SortParams *params = (SortParams *)arg;
    int *array = params->array;
    int start = params->start;
    int end = params->end;
    
    // Simple bubble sort for demonstration
    for (int i = start; i < end; i++) {
        for (int j = start; j < end - 1 - (i - start); j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
    return NULL;
}

void merge(int *array, int start, int mid, int end) {
    int temp[end - start];
    int i = start, j = mid, k = 0;
    
    while (i < mid && j < end) {
        if (array[i] < array[j]) {
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
        }
    }
    
    while (i < mid) temp[k++] = array[i++];
    while (j < end) temp[k++] = array[j++];
    
    for (i = start, k = 0; i < end; i++, k++) {
        array[i] = temp[k];
    }
}

int main() {
    int array[ARRAY_SIZE] = {5, 2, 9, 1, 5, 6, 3, 8, 4, 7};
    pthread_t thread1, thread2;
    
    printf("Original array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    SortParams params1 = {array, 0, ARRAY_SIZE/2};
    SortParams params2 = {array, ARRAY_SIZE/2, ARRAY_SIZE};
    
    pthread_create(&thread1, NULL, sort_half, &params1);
    pthread_create(&thread2, NULL, sort_half, &params2);
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    merge(array, 0, ARRAY_SIZE/2, ARRAY_SIZE);
    
    printf("Sorted array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}
