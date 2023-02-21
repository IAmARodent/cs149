/**
 * Description: Program that gets numbers and outputs the numbers in reverse order.
 * Author names: Geronimo A
 * Last modified date: 2/20/2023
 * Creation date: 2/20/2023
 */
#include <stdio.h>
/**
 * Main function that gets numbers and outputs the numbers in reverse order.
 */
int main(void)
{
    const int NUM_ELEMENTS = 20; // Number of input integers
    int userVals[NUM_ELEMENTS];  // Array to hold the user's input integers
    // get input size
    int size;
    scanf("%d", &size);
    // get numbers
    for (int i = 0; i < size; i++)
    {
        int input;
        scanf("%d", &input);
        userVals[i] = input;
    }
    // reverse the inputs
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d,", userVals[i]);
    }
    printf("\n");
    return 0;
}
