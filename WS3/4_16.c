/**
 * Description: Program that gets multiple numbers and gets the max and average.
 * Author names: Geronimo A
 * Last modified date: 2/20/2023
 * Creation date: 2/20/2023
 */
#include <stdio.h>
/**
 * Main function that gets multiple numbers and gets the max and average.
 */
int main(void)
{
    // input
    int input;
    int total;
    double count = 0;
    scanf("%d", &input);
    int max = input;
    // algorithm to get max and get all the numbers
    while (input >= 0)
    {
        count++;
        if (max < input)
        {
            max = input;
        }
        total = total + input;
        scanf("%d", &input);
    }
    // gets average by dividing total and count
    double average = total / count;
    printf("%d ", max);
    printf("%0.2lf\n", average);
    return 0;
}
