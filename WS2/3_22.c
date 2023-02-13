/**
* Description: Program that returns the smallest number of three inputs.
* Author names: Geronimo A
* Last modified date: 2/13/2023
* Creation date: 2/13/2023
*/
#include <stdio.h>
/**
* Main function that returns the smallest number of three inputs
*/
int main(void) {
   // initializes three inputs
   int first;
   int second;
   int third;
   // gets inputs
   scanf("%d", &first);
   scanf("%d", &second);
   scanf("%d", &third);
   //perform operations
   int min = first;
   if(first > second){
      min = second;
   }
   if(second > third){
      min = third;
   }
   //print
   printf("%d\n", min);
   return 0;
}
