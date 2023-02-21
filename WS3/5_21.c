/**
 * Description: Program that takes in words and a letter and outputs the words that contain that letter.
 * Author names: Geronimo A
 * Last modified date: 2/20/2023
 * Creation date: 2/20/2023
 */
#include <stdio.h>
#include <string.h>
/**
 * Main function that takes in words and a letter and outputs the words that contain that letter.
 */
int main(void)
{
    // string array
    char words[20][10];
    // get size
    int size;
    scanf("%d", &size);
    // get words
    for (int i = 0; i < size; i++)
    {
        scanf("%s", words[i]);
    }

    char searchCharacter;
    scanf(" %c", &searchCharacter);
    // checks each word
    for (int i = 0; i < sizeof(words); i++)
    {
        // checks each letter
        for (int j = 0; j < sizeof(words[0]); j++)
        {
            if (words[i][j] == searchCharacter)
            {
                printf("%s,", words[i]);
                break;
            }
        }
    }
    printf("\n");
    return 0;
}
