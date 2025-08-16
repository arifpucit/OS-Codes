//func-calling.c
#include <stdio.h>
#include <stdlib.h>
int f2(int a){
   int b = a + 1;
   return b;
}

int f1(long a, long b, long c, long d, long e, long f, long g, long h){
   unsigned long f1_var1 = 0x123456789;
   unsigned long f1_var2 = 0x0abcdef;
   int rv = f2(5);
   return 1;
}

int main(int argc, char* argv[]){
   unsigned long main_var1 = 0x1122334455667788;
   unsigned long main_var2 = 0x99aabbccddeeff00;
   char *main_str2 = "Arif";
   int rv_f1 = f1(0x11111111, 0x22222222, 0x33333333, 0x44444444, 0x55555555, 0x66666666, 0x77777777, 0x88888888);
   return 0;
}
