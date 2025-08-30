/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  barrier1.c: 
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* worker(void* arg);

int main() {
    pthread_t t1, t2, t3;
    int id1 = 1, id2 = 2, id3 = 3;
    
    printf("=== Program WITHOUT Barriers ===\n");
    printf("Notice: Some threads may start Phase 2 before others finish Phase 1\n\n");
    
    pthread_create(&t1, NULL, worker, &id1);
    pthread_create(&t2, NULL, worker, &id2);
    pthread_create(&t3, NULL, worker, &id3);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    
    printf("\nAll threads completed\n");
    return 0;
}

void* worker(void* arg) {
    int thread_id = *(int*)arg;
    
    // PHASE 1: Basic printing task
    printf("Thread %d: Starting Phase 1\n", thread_id);
    sleep(thread_id);  // Simulate different work durations
    printf("Thread %d: Finished Phase 1\n", thread_id);
    
    // NO BARRIER HERE - Threads proceed immediately to Phase 2
    
    // PHASE 2: Basic printing task  
    printf("Thread %d: Starting Phase 2\n", thread_id);
    sleep(1);
    printf("Thread %d: Finished Phase 2\n", thread_id);
    
    pthread_exit(NULL);
}
