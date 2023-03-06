/**
 * Description: Program that reads a txt file and reads all the names in the files.
 * Author names: Geronimo A
 * Last modified date: 3/6/2023
 * Creation date: 3/6/2023
 */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_SUPPORTED_NAMES 1000
#define MAX_SUPPORTED_NAMES_PER_FILE 200
int countNamesInFile(char fileName[], int fd1[2], int fd2[2])
{
    // opens the file in read mode
    if (fileName == NULL)
    {
        return 0;
    }
    FILE *names;
    names = fopen(fileName, "r");
    // check if file exists
    if (names == NULL)
    {
        fprintf(stderr, "Warning - File %s cannot be read or found\n", fileName);
        return 1;
    }
    // array for names and unique names
    char allNames[MAX_SUPPORTED_NAMES_PER_FILE][30];
    char uniqueNames[MAX_SUPPORTED_NAMES_PER_FILE][30];
    // counts the number of names existing in the uniqueNamesArray
    int uniqueNamesCounter = 1;
    // duplicate and doesntExistInUnique used as booleans in creating the uniqueNamesArray within conditions
    int duplicate = 0;
    int doesntExistInUnique = 1;
    // works in tandem with uniqueNames array to display amount of each unique name
    int uniqueNamesCounterArray[MAX_SUPPORTED_NAMES_PER_FILE];
    // line that holds the current line when reading file
    char line[30];
    char emptyString[] = "\n";
    int nameCounter = 0;
    int lineCounter = 1;
    // reads the names of the file and puts it into allNames array until there are no more lines left
    while (NULL != fgets(line, 30, names))
    {
        // if line is empty notify user
        if (strcmp(line, emptyString) == 0)
        {
            fprintf(stderr, "Warning- Line %d of file %s empty.\n", lineCounter, fileName);
            lineCounter++;
        }
        // else put name in allNamesArray
        else
        {
            // checks for last name in file where it does not have a new line at the end of the name
            if (line[strlen(line) - 1] != '\n')
            {
                strcpy(allNames[nameCounter], line);
                nameCounter++;
            }
            // normal cases
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
    // puts the first name into the uniqueNames array since it is empty
    strcpy(uniqueNames[0], allNames[0]);
    // create unique names array
    for (int i = 1; i < nameCounter; i++)
    {
        for (int j = 0; j < uniqueNamesCounter; j++)
        {
            // if the name already exists set doesntExistInUnique to false
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
        // if not duplicate and doesntExistInUnique copy current name to uniqueNamesArray
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
            // if uniqueName shows up in allNames increase count
            if (strcmp(uniqueNames[i], allNames[j]) == 0)
            {
                counter++;
            }
        }
        // apply count to the corresponding name in uniqueNames
        uniqueNamesCounterArray[i] = counter;
    }
    fclose(names);
    write(fd1[1], uniqueNames, sizeof(uniqueNames));
    write(fd2[1], &uniqueNamesCounterArray, sizeof(uniqueNamesCounterArray));
    return 0;
}
/**
 * Main method that reads a txt file and reads all the names in the file.
 * The names are then counted one by one to see which names are outputted the most and prints the frequency of each name in the console.
 */
int main(int argc, char *argv[])
{
    char fileNames[100][100];

    char allFilesNames[MAX_SUPPORTED_NAMES][30];
    char nameBuffer[MAX_SUPPORTED_NAMES_PER_FILE][30];

    int allFilesCounter[MAX_SUPPORTED_NAMES];
    int numberBuffer[MAX_SUPPORTED_NAMES_PER_FILE];

    char unique[MAX_SUPPORTED_NAMES][30];
    int uniqueCounter[MAX_SUPPORTED_NAMES];
    int uniqueNames;
    for (int i = 0; i < argc - 1; i++)
    {
        strcpy(fileNames[i], argv[i + 1]);
    }
    int numberOfReadableFiles = argc - 1;
    int readableFilesCount = 0;
    char readableFiles[100][100];
    for (int i = 0; i < argc - 1; i++)
    {
        FILE *names;
        names = fopen(fileNames[i], "r");
        if (names == NULL)
        {
            fprintf(stderr, "Warning - File %s cannot be read or found\n", fileNames[i]);
            numberOfReadableFiles--;
        }
        else
        {
            fclose(names);
            strcpy(readableFiles[readableFilesCount], fileNames[i]);
            readableFilesCount++;
        }
    }
    for (int i = 0; i < numberOfReadableFiles; i++)
    {
        printf("%s\n", readableFiles[i]);
    }
    printf("%d\n", numberOfReadableFiles);
    int fdName[numberOfReadableFiles][2];
    int fdNumber[numberOfReadableFiles][2];
    for (int i = 0; i < numberOfReadableFiles; i++)
    {
        pipe(fdName[i]);
        pipe(fdNumber[i]);
    }
    for (int i = 0; i < numberOfReadableFiles; i++)
    {
        int id = fork();
        if (id == 0)
        { // 01 23 45 67 89 1011
            countNamesInFile(readableFiles[i], fdName[i], fdNumber[i]);
            return 0;
        }
    }
    if (numberOfReadableFiles == 0)
    {
        return 0;
    }
    while (wait(NULL) > 0)
    {
        // printf("waiting for child to terminate\n");
    }
    for (int i = 0; i < numberOfReadableFiles; i++)
    {
        read(fdName[i][0], allFilesNames[i * MAX_SUPPORTED_NAMES_PER_FILE], sizeof(nameBuffer));
        read(fdNumber[i][0], &allFilesCounter[i * MAX_SUPPORTED_NAMES_PER_FILE], sizeof(numberBuffer));
    }
    for (int i = 0; i < MAX_SUPPORTED_NAMES; i += 200)
    {
        for (int j = 100 + i; j < MAX_SUPPORTED_NAMES_PER_FILE + i; j++)
        {
            strcpy(allFilesNames[j], "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0");
        }
    }

    for (int i = 0; i < MAX_SUPPORTED_NAMES; i++) // goes through allFilesNames array
    {
        int exists = 1;
        char current[30] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
        strcpy(current, allFilesNames[i]);
        // printf("%s", current);
        for (int j = 0; j < uniqueNames; j++) // checks if name exists already in unique
        {
            if (strcmp(current, unique[j]) == 0 || strcmp(current, "\n") == 0 || strcmp(current, "\0") == 0)
            {
                exists = 0;
            }
        }
        if (exists == 1) // if name does not exist in unique
        {
            int count = 0;
            printf("%s index of allnames%d\n", current, i);
            strcpy(unique[uniqueNames], current);         // put current name in unique array
            for (int j = i; j < MAX_SUPPORTED_NAMES; j++) // check each name in allFilesNames and add value to count
            {
                if (strcmp(current, allFilesNames[j]) == 0)
                {
                    count += allFilesCounter[j];
                }
            }
            uniqueCounter[uniqueNames] = count; // add counter to unique counter
            uniqueNames++;                      // increment amount of unique names
        }
    }
    for (int i = 0; i < uniqueNames; i++)
    {
        printf("%s %d\n", unique[i], uniqueCounter[i]);
    }
    return 0;
}