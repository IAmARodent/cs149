/**
 * Description: Program that returns if a set of numbers are multiples of 10.
 * Author names: Geronimo A
 * Last modified date: 3/12/2023
 * Creation date: 3/12/2023
 */
#include <stdio.h>
#include <stdbool.h>
/**
 * Function that checks if the set of numbers has all multiples of 10.
 * Parameter: int[] inputVals - inputs int numVals - number of inputs
 */
bool IsArrayMult10(int inputVals[], int numVals)
{
    bool yes = true;
    for (int i = 0; i < numVals; i++)
    {
        if (inputVals[i] % 10 == 0)
        {
            // nothing
        }
        else
        {
            yes = false;
        }
    }
    return yes;
}
/**
 * Function that checks if the set of numbers has no multiples of 10
 * Parameter: int[] inputVals - inputs int numVals - number of inputs
 */
bool IsArrayNoMult10(int inputVals[], int numVals)
{
    bool yes = true;
    for (int i = 0; i < numVals; i++)
    {
        if (inputVals[i] % 10 == 0)
        {
            yes = false;
        }
    }
    return yes;
}
/**
 * Main function that returns if a set of numbers are multiples of 10.
 */
int main(void)
{
    //gets all the inputs
    int size;
    scanf("%d", &size);
    int numbers[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &numbers[i]);
    }
    //gets the boolean values from functions
    bool mult1 = IsArrayMult10(numbers, size);
    if (mult1 == true)
    {
        printf("all multiples of 10\n");
        return 0;
    }
    bool mult2 = IsArrayNoMult10(numbers, size);
    if (mult2 == false)
    {
        printf("mixed values\n");
    }
    else
    {
        printf("no multiples of 10\n");
    }
    return 0;
}
