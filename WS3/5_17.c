/**
 * Description: Program that gets numbers and outputs the middle number.
 * Author names: Geronimo A
 * Last modified date: 2/20/2023
 * Creation date: 2/20/2023
 */
#include <stdio.h>
/**
 * Main function that gets numbers and outputs the middle number.
 */
int main(void)
{
    // Max number of elements
    const int NUM_ELEMENTS = 9;
    int userValues[NUM_ELEMENTS]; // Set of data specified by the user
    // inputs
    int input;
    int i = 0;
    scanf("%d", &input);
    userValues[i] = input;
    i++;
    // algorithm to get numbers
    while (input > 0)
    {
        scanf("%d", &input);
        userValues[i] = input;
        i++;
    }
    // if there are more than 9 numbers
    if (i > 10)
    {
        printf("Too many numbers\n");
    }
    // gets the middle number
    else
    {
        i--;
        i /= 2;
        printf("Middle item: %d\n", userValues[i]);
    }

    return 0;
}
