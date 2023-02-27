/**
 * Description: Program that gets 4 numbers and returns max and min via functions.
 * Author names: Geronimo A
 * Last modified date: 2/21/2023
 * Creation date: 2/21/2023
 */
#include <stdio.h>
/**
 * Function that calculates the max from 4 numbers.
 * Parameter: num 1 - first number num2 - second number num3 - third number num4- fourth number
 * Return: max number
*/
int MaxNumber(int num1, int num2, int num3, int num4)
{
    int max = num1;
    if (max < num2)
    {
        max = num2;
    }
    if (max < num3)
    {
        max = num3;
    }
    if (max < num4)
    {
        max = num4;
    }
    return max;
}
/**
 * Function that calculates the min from 4 numbers.
 * Parameter: num1 - first number num2 - second number num3 - third number num4 - fourth number
 * Return: mininum number
*/
int MinNumber(int num1, int num2, int num3, int num4)
{
    int min = num1;
    if (min > num2)
    {
        min = num2;
    }
    if (min > num3)
    {
        min = num3;
    }
    if (min > num4)
    {
        min = num4;
    }
    return min;
}
/**
 * Main function that gets 4 numbers and returns max and min via functions.
*/
int main(void)
{
    int numbers[4];
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &numbers[i]);
    }
    printf("Maximum is %d\n", MaxNumber(numbers[0], numbers[1], numbers[2], numbers[3]));
    printf("Minimum is %d\n", MinNumber(numbers[0], numbers[1], numbers[2], numbers[3]));

    return 0;
}
