#include <stdio.h>
#include <string.h>
int main(void)
{
    FILE *names;
    names = fopen("names.txt", "r");

    char allNames[1000][30];
    char uniqueNames[1000][30];
    int uniqueNamesCounter = 1;
    int duplicate = 0;
    int test = 1;
    int uniqueNamesCounterArray[1000];

    char line[30];
    char emptyString[] = "\n";
    int nameCounter = 0;
    while (NULL != fgets(line, 30, names))
    {
        if (strcmp(line, emptyString) == 0)
        {
            printf("Line %d empty.\n", nameCounter + 1);
        }
        else
        {
            char tempLine[30];
            strncpy(tempLine, line, strlen(line)-1);
            strcpy(allNames[nameCounter], tempLine);
            memset(tempLine, 0, 30);
            nameCounter++;
        }
    }
    strcpy(uniqueNames[0], allNames[0]);
    // create unique names array
    for(int i = 1; i < nameCounter; i++)
    {
        for(int j = 0; j < uniqueNamesCounter; j++)
        {
            if(strcmp(allNames[i], uniqueNames[j]) == 0)
            {
                test = 0;
            }
            else
            {
                duplicate = 1;
            }
        }
        if(duplicate == 1 && test == 1)
        {
            strcpy(uniqueNames[uniqueNamesCounter], allNames[i]);
            uniqueNamesCounter++;
            duplicate = 0;
        }
        test = 1;
    }
    //get counts for each unique name
    for(int i = 0; i < uniqueNamesCounter; i++)
    {
        int counter = 0;
        for(int j = 0; j < nameCounter; j++)
        {
            if(strcmp(uniqueNames[i], allNames[j]) == 0)
            {
                counter++;
            }
        }
        uniqueNamesCounterArray[i] = counter;
    }
    for(int i = 0; i < uniqueNamesCounter; i++)
    {
        printf("%s: %d\n", uniqueNames[i], uniqueNamesCounterArray[i]);
    }
    return 0;
}