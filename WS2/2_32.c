/**
* Description: Program that takes in inputs for original price and current price of a mortgage and does calculations.
* Author names: Geronimo A
* Last modified date: 2/13/2023
* Creation date: 2/13/2023
*/
#include <stdio.h>
/**
** Main function that takes in inputs for original price and current price of a mortgage and does calculations.
*/
int main(void) {
   // initilizes inputs
   int currentPrice;
   int lastMonthsPrice;
   // gets the inputs
   scanf("%d", &currentPrice);
   scanf("%d", &lastMonthsPrice);
   // performs operations
   int first = currentPrice-lastMonthsPrice;
   double second = (currentPrice*0.051)/12;
   //print
   printf("This house is $%d. The change is $%d since last month.\nThe estimated monthly mortgage is $%0.6lf.\n", currentPrice, first, second);
   return 0;
}
