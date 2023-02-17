#include <stdio.h>
#include <string.h>
/**
 * Main method that reads a file named names.txt and reads all the names in the file. 
 * The names are then counted one by one to see which names are outputted the most and prints the frequency of each name in the console.
*/
int main(void)
{
    //opens the file in read mode
    FILE *names;
    names = fopen("names.txt", "r");
    //array for names and unique names
    char allNames[1000][30];
    char uniqueNames[1000][30];
    //counts the number of names existing in the uniqueNamesArray
    int uniqueNamesCounter = 1;
    //duplicate and test used as booleans in creating the uniqueNamesArray within conditions
    int duplicate = 0;
    int doesntExistInUnique = 1;
    //works in tandem with uniqueNames array to display amount of each unique name
    int uniqueNamesCounterArray[1000];
    //line that holds the current line when reading file
    char line[30];
    char emptyString[] = "\n";
    int nameCounter = 0;
    //reads the names of the file and puts it into allNames array until there are no more lines left
    while (NULL != fgets(line, 30, names))
    {
        //if line is empty notify user
        if (strcmp(line, emptyString) == 0)
        {
            printf("Line %d empty.\n", nameCounter + 1);
        }
        //else put name in allNamesArray
        else
        {
            //checks for last name in file where it does not have a new line at the end of the name
            if(line[strlen(line)-1] != '\n')
            {
                strcpy(allNames[nameCounter], line);
                nameCounter++;
            }
            //normal cases
            else
            {
                char tempLine[30];
                strncpy(tempLine, line, strlen(line) - 1);
                strcpy(allNames[nameCounter], tempLine);
                memset(tempLine, 0, 30);
                nameCounter++;
            }
        }
    }
    //puts the first name into the uniqueNames array since it is empty
    strcpy(uniqueNames[0], allNames[0]);
    // create unique names array
    for (int i = 1; i < nameCounter; i++)
    {
        for (int j = 0; j < uniqueNamesCounter; j++)
        {
            //if the name already exists set doesntExistInUnique to false
            if (strcmp(allNames[i], uniqueNames[j]) == 0)
            {
                doesntExistInUnique = 0;
            }
            // else it is a duplicate
            else
            {
                duplicate = 1;
            }
        }
        //if not duplicate and doesntExistInUnique copy current name to uniqueNamesArray
        if (duplicate == 1 && doesntExistInUnique == 1)
        {
            strcpy(uniqueNames[uniqueNamesCounter], allNames[i]);
            uniqueNamesCounter++;
            duplicate = 0;
        }
        doesntExistInUnique = 1;
    }
    // get counts for each unique name
    for (int i = 0; i < uniqueNamesCounter; i++)
    {
        int counter = 0;
        for (int j = 0; j < nameCounter; j++)
        {
            //if uniqueName shows up in allNames increase count
            if (strcmp(uniqueNames[i], allNames[j]) == 0)
            {
                counter++;
            }
        }
        //apply count to the corresponding name in uniqueNames
        uniqueNamesCounterArray[i] = counter;
    }
    //output of the program
    for (int i = 0; i < uniqueNamesCounter; i++)
    {
        printf("%s: %d\n", uniqueNames[i], uniqueNamesCounterArray[i]);
    }
    return 0;
}