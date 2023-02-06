/**
* Description: Program that prints an arrow from user inputs.
* Author names: Geronimo A
* Last modified date: 2/6/2023
* Creation date: 2/6/2023
*/
#include <stdio.h>
/**
* Main function that prints an arrow from user inputs.
*/
int main(void) {
   int baseInt;
   int headInt;
   
   /* Type your code here. */
   scanf("%d",&baseInt);
   scanf("%d",&headInt);
   printf("    %d\n", headInt);
   printf("    %d%d\n", headInt, headInt);
   printf("%d%d%d%d", baseInt, baseInt, baseInt, baseInt);
   printf("%d%d%d\n", headInt, headInt, headInt);
   printf("%d%d%d%d", baseInt, baseInt, baseInt,baseInt);
   printf("%d%d%d%d\n",headInt,headInt, headInt, headInt);
   printf("%d%d%d%d", baseInt, baseInt, baseInt, baseInt);
   printf("%d%d%d\n", headInt, headInt, headInt);
   printf("    %d%d\n", headInt, headInt);
   printf("    %d\n", headInt);
   return 0;
}
