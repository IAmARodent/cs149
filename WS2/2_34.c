/**
* Description: Program that takes in a username input and displays a welcome message.
* Author names: Geronimo A
* Last modified date: 2/13/2023
* Creation date: 2/13/2023
*/
#include <stdio.h>
/**
* Main function that takes in a username and displays a welcome messasge.
*/
int main(void) {
   char userName[50];
   // gets input
   scanf("%s", userName);
   // print
   printf("Hello %s, and welcome to CS Online!\n", userName);
   return 0;
}
