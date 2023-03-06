/**
 * Description: Program that gets a string input and returns the count of characters excluding some special characters.
 * Author names: Geronimo A
 * Last modified date: 3/6/2023
 * Creation date: 3/6/2023
 */
#include <stdio.h>
#include <string.h>
/**
 * Main function that gets a string input and returns the count of characters excluding some special characters.
*/
int main(void)
{
    //gets input
    char str[50];
    fgets(str, 50, stdin);
    int count = 0;
    //checks each character
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ' && str[i] != '.' && str[i] != '!' && str[i] != ',')
        {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
