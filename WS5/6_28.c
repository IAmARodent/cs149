/**
 * Description: Program that gets a string input and prints the string with only alphabetical characters via functions.
 * Author names: Geronimo A
 * Last modified date: 3/6/2023
 * Creation date: 3/6/2023
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
/**
 * Function that removes special characters from strings.
 * Parameter: char userString - the string inputed char userStringAlphaOnly - the string after operation
*/
void RemoveNonAlpha(char userString[], char userStringAlphaOnly[])
{
    int count = 0;
    for (int i = 0; i < strlen(userString); i++)
    {
        if ((userString[i] >= 65 && userString[i] <= 90) || (userString[i] >= 97 && userString[i] <= 122))
        {
            userStringAlphaOnly[count] = userString[i];
            count++;
        }
    }
}
/**
 * Main function that gets a string input and prints the string with only alphabetical characters via functions.
*/
int main(void)
{
    char str[50];
    fgets(str, 50, stdin);
    char strFinal[50] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
                         '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
                         '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
                         '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
                         '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
    RemoveNonAlpha(str, strFinal);
    printf("%s\n", strFinal);

    return 0;
}
