#include <stdio.h>
#include <stdlib.h>

// User-defined function to calculate factorial
int factorial(int n) {
    int result = 1;
    int i;
    
    for (i = 1; i <= n; i++) {
        result = result * i;
    }
    
    return result;
}

// Another simple function for demonstration
void print_info(char *name, int age) {
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    
    if (age >= 18) {
        printf("Status: Adult\n");
    } else {
        printf("Status: Minor\n");
    }
}

int main() {
    // Various types of variables for demonstration
    int num = 5;
    char student_name[] = "Alice";
    int student_age = 20;
    float gpa = 3.75;
    int *ptr_num = &num;
    int fact_result;
    
    printf("=== GDB Debugging Demo Program ===\n");
    
    // Call user-defined functions
    print_info(student_name, student_age);
    
    printf("\nCalculating factorial of %d...\n", num);
    fact_result = factorial(num);
    
    printf("Factorial of %d is: %d\n", num, fact_result);
    printf("GPA: %.2f\n", gpa);
    printf("Address of num: %p\n", (void*)ptr_num);
    printf("Value through pointer: %d\n", *ptr_num);
    
    // Modify values for demonstration
    num = 7;
    *ptr_num = 10;  // This will change num to 10
    
    printf("Modified num: %d\n", num);
    
    return 0;
}
