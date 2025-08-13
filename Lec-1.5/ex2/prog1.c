/*
*  Video Lecture: 04
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/

#include <stdio.h>
#include <mymath.h>
int main(){
   double x, y;
   printf("Enter first number: ");
   scanf("%lf",&x);
   printf("Enter second number: ");
   scanf("%lf",&y);
   double ans1 = myadd(x,y);
   double ans2 = mysub(x,y);
   double ans3 = mymul(x,y);
   double ans4 = mydiv(x,y);
   printf("a + b = %7.2lf\n",ans1);
   printf("a - b = %7.2lf\n",ans2);
   printf("a * b = %7.2lf\n",ans3);
   printf("a/b   = %7.2lf\n",ans4);
   return 0;
}
