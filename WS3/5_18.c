/**
 * Description: Program that gets the list of integers and a threshold and outputs the numbers below the threshold.
 * Author names: Geronimo A
 * Last modified date: 2/20/2023
 * Creation date: 2/20/2023
 */
#include <stdio.h>
/**
 * Main function that gets the list of integers and a threshold and outputs the numbers below the threshold.
 */
int main(void)
{
    // max array size
    const int NUM_ELEMENTS = 20;
    int userValues[NUM_ELEMENTS]; // Set of data specified by the user
    // gets size of array
    int size;
    scanf("%d", &size);
    // gets numbers
    for (int i = 0; i <= size; i++)
    {
        int input;
        scanf("%d", &input);
        userValues[i] = input;
    }
    // outputs the numbers below threshold
    for (int i = 0; i <= size; i++)
    {
        if (userValues[i] < userValues[size])
        {
            printf("%d,", userValues[i]);
        }
    }
    printf("\n");
    return 0;
}
