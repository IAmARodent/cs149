/**
 * Description: Program that takes a positive integer and converts it to binary but in reverse.
 * Author names: Geronimo A
 * Last modified date: 2/20/2023
 * Creation date: 2/20/2023
 */
#include <stdio.h>
/**
 * Main function that that takes a positive integer and converts it to binary but in reverse.
 */
int main(void)
{
    // input
    int input;
    scanf("%d", &input);
    // algorithm that reverses string to binary
    while (input > 0)
    {
        int output;
        output = input % 2;
        printf("%d", output);
        input /= 2;
    }
    printf("\n");
    return 0;
}
