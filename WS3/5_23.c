/**
 * Description: Program that gets the two smallest numbers from a list of numbers.
 * Author names: Geronimo A
 * Last modified date: 2/20/2023
 * Creation date: 2/20/2023
 */
#include <stdio.h>
/**
 * Main function that gets the two smallest numbers from a list of numbers.
*/
int main(void)
{
    //size of array
    int size;
    scanf("%d", &size);
    //get numbers
    int numbers[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &numbers[i]);
    }
    int first = numbers[0];
    int second = numbers[1];
    //gets the second number and if the second number is smaller than the first number then it swaps.
    for (int i = 2; i < size; i++)
    {
        if (numbers[i] < first)
        {
            second = first;
            first = numbers[i];
        }
        else if (numbers[i] < second)
        {
            second = numbers[i];
        }
    }
    printf("%d and %d\n", first, second);
    return 0;
}
