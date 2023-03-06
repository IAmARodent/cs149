/**
* Description: Program that reads a txt file and reads all the names in the files.
* Author names: Geronimo A
* Last modified date: 2/20/2023
* Creation date: 2/20/2023
*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int countNamesInFile(char fileName[], int fd1[2], int fd2[2])
{
    //opens the file in read mode
    if(fileName == NULL)
    {
        return 0;
    }
    FILE *names;
    names = fopen(fileName, "r");
    //check if file exists
    if(names == NULL)
    {
        fprintf(stderr, "Warning - File %s cannot be read or found\n", fileName);
        return 1;
    }
    //array for names and unique names
    char allNames[1000][30];
    char uniqueNames[1000][30];
    //counts the number of names existing in the uniqueNamesArray
    int uniqueNamesCounter = 1;
    //duplicate and doesntExistInUnique used as booleans in creating the uniqueNamesArray within conditions
    int duplicate = 0;
    int doesntExistInUnique = 1;
    //works in tandem with uniqueNames array to display amount of each unique name
    int uniqueNamesCounterArray[1000];
    //line that holds the current line when reading file
    char line[30];
    char emptyString[] = "\n";
    int nameCounter = 0;
    int lineCounter = 1;
    //reads the names of the file and puts it into allNames array until there are no more lines left
    while (NULL != fgets(line, 30, names))
    {
        //if line is empty notify user
        if (strcmp(line, emptyString) == 0)
        {
            fprintf(stderr, "Warning- Line %d empty.\n", lineCounter);
            lineCounter++;
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
                lineCounter++;
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
    fclose(names);
    write(fd1[1], uniqueNames, sizeof(uniqueNames));
    write(fd2[1], uniqueNamesCounterArray, sizeof(uniqueNamesCounterArray));
    return 0;
}
/**
 * Main method that reads a txt file and reads all the names in the file. 
 * The names are then counted one by one to see which names are outputted the most and prints the frequency of each name in the console.
*/
int main(int argc, char *argv[])
{
    int id;
    char fileNames[100][100];
    
    char allFilesNames[10000][30];
    char nameBuffer[1000][30];

    char allFilesCounter[10000];
    char numberBuffer[1000];

    for(int i = 0; i < argc - 1; i++)
    {
        strcpy(fileNames[i], argv[i+1]);
        printf("%d,%s\n", i, fileNames[i]);
    }
    int fdName[argc-1][2];
    int fdNumber[argc-1][2];
    for(int i = 0; i < argc-1; i++)
    {
        pipe(fdName[i]);
        pipe(fdNumber[i]);
    }
    char* hi = "test";
    char message[4];
    //write(fd[1][1], hi, 4);
    //read(fd[1][0], message, 4);
    for(int i = 0; i < argc-1; i++)
    {
        int id = fork();
        if(id == 0)
        { //01 23 45 67 89 1011
            countNamesInFile(fileNames[i], fdName[i], fdNumber[i]);
            return 0;
        }
    }
    while(wait(NULL) > 0)
    {
        printf("waiting for child to terminate\n");
    }
    for(int i = 0; i < argc-1; i++)
    {
        read(fdName[i][0],allFilesNames[i*1000],sizeof(nameBuffer));
        read(fdNumber[i][0], allFilesCounter[i*1000], sizeof(numberBuffer));
    }
    for(int i = 0; i < 5; i++)
    {
        printf("%s %d\n",allFilesNames[i], allFilesCounter[i]);
    }
    return 0;
}