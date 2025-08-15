#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>

int main(){
    clock_t start, end;
    pid_t pid;
    double cpu_time_used;
    
    printf("Testing fork() with 1000 iterations...\n");
    start = clock();
    
    for(int i = 0; i < 1000; i++){
        pid = fork();
        if(pid == 0) {
            // Child process
            exit(0);
        } else if(pid > 0) {
            // Parent process
            wait(NULL);
        }
    }
    
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("fork() time: %.6f seconds\n", cpu_time_used);
    
    printf("\nTesting vfork() with 1000 iterations...\n");
    start = clock();
    
    for(int i = 0; i < 1000; i++){
        pid = vfork();
        if(pid == 0) {
            // Child process
            exit(0);
        }
        // Parent automatically continues after child exits with vfork()
    }
    
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("vfork() time: %.6f seconds\n", cpu_time_used);
    
    return 0;
}
