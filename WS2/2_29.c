/**
* Description: Program that takes three inputs and does various mathemetical functions with the inputs.
* Author names: Geronimo A
* Last modified date: 2/13/2023
* Creation date: 2/13/2023
*/
#include <stdio.h>
#include <math.h>
/**
* Main function that takes three inputs and does various mathemitical fucntions with the inputs
*/
int main(void) {
   // initilize inputs
   double x;
   double y;
   double z;
   //take input
   scanf("%lf", &x);
   scanf("%lf", &y);
   scanf("%lf", &z);
   // initilize outputs of mathematical functions
   double first;
   double second;
   double third;
   double fourth;
   // perform mathematical functions
   first = pow(x,z); 
   second = pow(x,pow(y,2));
   third = fabs(y);
   fourth = sqrt(pow((x*y),z));
   //print
   printf("%0.2lf %0.2lf %0.2lf %0.2lf\n", first, second, third, fourth);
   return 0;
}
