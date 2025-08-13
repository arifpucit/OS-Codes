//ex6.c
#include <stdio.h>
int foo(int, int);
int main(void){
   int val1 = 10;
   int val2 = 20;
   int sum = foo(val1, val2);
   printf("sum is: %d\n", sum);
   return 0;
}

int foo(int a, int b){
   int out = a + b;
   return out;
}
