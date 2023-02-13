/**
* Description: Program that divides an input by another input three times.
* Author names: Geronimo A
* Last modified date: 2/13/2023
* Creation date: 2/13/2023
*/
#include <stdio.h>
/**
* Main function that divides an input by another input three times
*/
int main(void) {
   // initilize inputs
   int userNum;
   int x;
   //get inputs
   scanf("%d", &userNum);
   scanf("%d", &x);
   // initilize outputs
   int first;
   int second;
   int third;
   // perform operations
   first = userNum / x;
   second = first / x;
   third = second / x;
   //print
   printf("%d %d %d\n", first, second, third);
   return 0;
}
