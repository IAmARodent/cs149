/**
 * Description: Program that gets numbers and bounds and outputs the numbers between the bounds.
 * Author names: Geronimo A
 * Last modified date: 2/20/2023
 * Creation date: 2/20/2023
 */
#include <stdio.h>
/**
 * Main function that gets numbers and bounds and outputs the numbers between the bounds.
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
    int lower;
    int upper;
    scanf("%d", &lower);
    scanf("%d", &upper);
    //get numbers according to bounds
    for (int i = 0; i < size; i++)
    {
        if (numbers[i] <= upper && numbers[i] >= lower)
        {
            printf("%d,", numbers[i]);
        }
    }
    printf("\n");
    return 0;
}
