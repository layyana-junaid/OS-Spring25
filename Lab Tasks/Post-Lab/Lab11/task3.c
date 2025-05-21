#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_TELLERS 3
#define NUM_CUSTOMERS 10

int account_balance = 1000;
pthread_mutex_t balance_mutex = PTHREAD_MUTEX_INITIALIZER;

void *teller_service(void *arg) {
    int customer_id = *(int *)arg;
    int amount = (rand() % 100) - 50; // Random transaction between -50 and 49
    
    pthread_mutex_lock(&balance_mutex);
    
    printf("Teller %ld serving customer %d with transaction: %d\n", 
           pthread_self() % 1000, customer_id, amount);
    
    account_balance += amount;
    printf("New balance: %d\n", account_balance);
    
    pthread_mutex_unlock(&balance_mutex);
    
    // Simulate processing time
    usleep(100000 + (rand() % 200000));
    
    return NULL;
}

int main() {
    pthread_t tellers[NUM_TELLERS];
    int customer_ids[NUM_CUSTOMERS];
    
    srand(time(NULL));
    
    for (int i = 0; i < NUM_CUSTOMERS; i++) {
        customer_ids[i] = i + 1;
        pthread_create(&tellers[i % NUM_TELLERS], NULL, teller_service, &customer_ids[i]);
    }
    
    for (int i = 0; i < NUM_TELLERS; i++) {
        pthread_join(tellers[i], NULL);
    }
    
    printf("Final account balance: %d\n", account_balance);
    
    return 0;
}
