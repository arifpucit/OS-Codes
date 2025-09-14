/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  counting_sems.c: Named Semaphores 
*  compile: $ gcc counting_sems.c -lpthread
*  usage: $./a.out 
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

void* worker_thread(void* arg);

sem_t counting_sem;

int main(){
    printf("=== POSIX Counting Semaphore Demo ===\n");
    printf("Semaphore initialized to 5 (allows 5 concurrent threads)\n");
    printf("Creating 10 threads - only 5 can be 'in office' at once\n\n");
    
    // Initialize unnamed semaphore with value 5 (allows 5 concurrent threads)
    sem_init(&counting_sem, 0, 5);
    
    pthread_t tid[10];
    
    // Create 10 threads
    for(int i = 0; i < 10; i++){
        int* thread_id = malloc(sizeof(int)); //unique heap memory for each thread
        *thread_id = i + 1;
        pthread_create(&tid[i], NULL, worker_thread, thread_id);
        sleep(1); // Stagger thread creation to see the effect clearly
    }
    
    // Wait for all threads to complete
    for(int i = 0; i < 10; i++){
        pthread_join(tid[i], NULL);
    }
    
    sem_destroy(&counting_sem);
    printf("\nBye Bye from main...\n");
    return 0;
}

void* worker_thread(void* arg){
    int thread_id = *(int*)arg;
    free(arg); // Clean up allocated memory
    
    printf("Thread %d: Waiting to enter office...\n", thread_id);
    
    // Acquire semaphore (decrement count)
    sem_wait(&counting_sem);
    
    // Critical section - simulating being "in the office"
    printf("Thread %d: Entered office! Working...\n", thread_id);
    
    int sem_value;
    sem_getvalue(&counting_sem, &sem_value);
    printf("Thread %d: Current semaphore value = %d\n", thread_id, sem_value);
    
    // Simulate some work
    sleep(3);
    
    printf("Thread %d: Leaving office...\n", thread_id);
    
    // Release semaphore (increment count)
    sem_post(&counting_sem);
    
    pthread_exit(NULL);
}
