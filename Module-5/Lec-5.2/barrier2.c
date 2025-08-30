/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  barrier2.c: 
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* worker(void* arg);

// Barrier to synchronize threads between phases
pthread_barrier_t phase_barrier;

int main() {
    pthread_t t1, t2, t3;
    int id1 = 1, id2 = 2, id3 = 3;
    
    printf("=== Program WITH Barriers ===\n");
    printf("All threads must finish Phase 1 before ANY starts Phase 2\n\n");
    
    // Initialize barrier for 3 threads
    pthread_barrier_init(&phase_barrier, NULL, 3);
    
    pthread_create(&t1, NULL, worker, &id1);
    pthread_create(&t2, NULL, worker, &id2);
    pthread_create(&t3, NULL, worker, &id3);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    
    // Clean up barrier
    pthread_barrier_destroy(&phase_barrier);
    
    printf("\nAll threads completed\n");
    return 0;
}

void* worker(void* arg) {
    int thread_id = *(int*)arg;
    
    // PHASE 1: Basic printing task
    printf("Thread %d: Starting Phase 1\n", thread_id);
    sleep(thread_id);  // Simulate different work durations
    printf("Thread %d: Finished Phase 1\n", thread_id);
    
    // BARRIER: Wait for ALL threads to finish Phase 1
    printf("Thread %d: Waiting at barrier...\n", thread_id);
    pthread_barrier_wait(&phase_barrier);
    printf("Thread %d: Passed barrier - ALL threads finished Phase 1!\n", thread_id);
    
    // PHASE 2: Basic printing task
    printf("Thread %d: Starting Phase 2\n", thread_id);
    sleep(1);
    printf("Thread %d: Finished Phase 2\n", thread_id);
    
    pthread_exit(NULL);
}
