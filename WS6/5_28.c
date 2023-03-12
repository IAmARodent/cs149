/**
 * Description: Program that returns if a inputted string is a palindrome.
 * Author names: Geronimo A
 * Last modified date: 3/12/2023
 * Creation date: 3/12/2023
 */
#include <stdio.h>
#include <string.h>
/**
 * Main function that returns if a inputted string is a palindrome.
 */
int main(void)
{
    //initilizes various strings to null
    char string[50] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char stringWithoutSpaces[50] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char reverseString[50] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    //gets input
    fgets(string, 50, stdin);
    int stringLength = 0;
    //puts string to reverse
    for (int i = strlen(string) - 1; i >= 0; i--)
    {
        if (string[i] == ' ')
        {
            // nothing
        }
        else
        {
            reverseString[stringLength] = string[i];
            stringLength++;
        }
    }
    //remove spaces
    int stringWithoutSpacesLength = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == ' ')
        {
            // nothing
        }
        else
        {
            stringWithoutSpaces[stringWithoutSpacesLength] = string[i];
            stringWithoutSpacesLength++;
        }
    }
    //compares reversestring with the string without spaces
    if (strcmp(reverseString, stringWithoutSpaces) == 0)
    {
        printf("palindrome: %s\n", string);
    }
    else
    {
        printf("not a palindrome: %s\n", string);
    }
    return 0;
}
