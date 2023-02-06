/**
* Description: Program that asks for user input and outputs to user the square and cube of a number and adds and multiplies that number to another user generated number.
* Author names: Geronimo A
* Last modified date: 2/6/2023
* Creation date: 2/6/2023
*/
#include <stdio.h>
/**
* Main function that asks for user input and outputs to user the square and cube of a number and adds and multiplies that number to another user generated number.
*/
int main(void) {
   int userNum;
   
   printf("Enter integer:\n");
   scanf("%d", &userNum);
   /* Type your code here. */
   printf("You entered: %d\n", userNum);
   int userNum2 = userNum * userNum; 
   int userNum3 = userNum2 * userNum;
   printf("%d squared is %d\n", userNum, userNum2);
   printf("And %d cubed is %d!!\n", userNum, userNum3);
   printf("Enter another integer:\n");
   int secondNumber; 
   scanf("%d", &secondNumber);
   int addition = secondNumber + userNum; //stores additions of the two numbers
   int multiplication = secondNumber * userNum; //stores multiplication of the two numbers
   printf("%d + %d is %d\n", userNum, secondNumber, addition);
   printf("%d * %d is %d\n", userNum, secondNumber, multiplication);
   return 0;
}