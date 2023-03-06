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
#define MAX_SUPPORTED_NAMES 2000
#define MAX_SUPPORTED_NAMES_PER_FILE 200
/**
 * Function that gets a file name and processes and counts all the names of a file.
 * Param: fileName - name of file fd1 - name pipe fd2 - numbercounter pipe
 * Return: 0 Success 1 Fail
*/
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
                memset(tempLine, 0, 30);
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
    //writes uniqueNames and UniqueNamesCounterArray to process pipes.
    write(fd1[1], uniqueNames, sizeof(uniqueNames));
    write(fd2[1], &uniqueNamesCounterArray, sizeof(uniqueNamesCounterArray));
    return 0;
}
/**
 * Main method that reads multiple txt files and outputs the count of each name in all files
 * Each file is processed by its own process and each process outputs unique names and the times it happened.
 * In the parent process it compiles all the information send by the children from pipes and gets the total for each name.
 */
int main(int argc, char *argv[])
{
    //all file inputs
    char fileNames[100][100];

    //for all names in each file
    char allFilesNames[MAX_SUPPORTED_NAMES][30];
    char nameBuffer[MAX_SUPPORTED_NAMES_PER_FILE][30];

    //for all counters in each file
    int allFilesCounter[MAX_SUPPORTED_NAMES];
    int numberBuffer[MAX_SUPPORTED_NAMES_PER_FILE];

    //for each calculation to compile the totals from each file
    char unique[MAX_SUPPORTED_NAMES][30];
    int uniqueCounter[MAX_SUPPORTED_NAMES];
    int uniqueNames;
    
    //gets all the files
    for (int i = 0; i < argc - 1; i++)
    {
        strcpy(fileNames[i], argv[i + 1]);
    }

    int numberOfReadableFiles = argc - 1;
    int readableFilesCount = 0;
    char readableFiles[100][100];
    
    //gets the readable files
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

    //creates pipes based on how many files one for names and one for numbers
    int fdName[numberOfReadableFiles][2];
    int fdNumber[numberOfReadableFiles][2];
    for (int i = 0; i < numberOfReadableFiles; i++)
    {
        pipe(fdName[i]);
        pipe(fdNumber[i]);
    }
    //if there are no files 
    if (numberOfReadableFiles == 0)
    {
        return 0;
    }
    //creates a child process for each file
    for (int i = 0; i < numberOfReadableFiles; i++)
    { 
        int id = fork(); //forks parallelly with the amoutn of number of ReadableFiles
        if (id == 0) //child process
        { 
            countNamesInFile(readableFiles[i], fdName[i], fdNumber[i]);
            return 0;
        }
    }
    while (wait(NULL) > 0)
    {
        // printf("waiting for child to terminate\n");
    }
    //gets the information from each process
    for (int i = 0; i < numberOfReadableFiles; i++)
    {
        read(fdName[i][0], allFilesNames[i * MAX_SUPPORTED_NAMES_PER_FILE], sizeof(nameBuffer));
        read(fdNumber[i][0], &allFilesCounter[i * MAX_SUPPORTED_NAMES_PER_FILE], sizeof(numberBuffer));
        close(fdName[i][0]);
        close(fdNumber[i][0]);
        close(fdName[i][1]);
        close(fdNumber[i][1]);
    }
    //nulls out the master array with all names in order to avoid errors
    for (int i = 0; i < MAX_SUPPORTED_NAMES; i += 200)
    {
        for (int j = 100 + i; j < MAX_SUPPORTED_NAMES_PER_FILE + i; j++)
        {
            strcpy(allFilesNames[j], "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0");
        }
    }
    //goes through each name and checks the master name array and if it matches it will add the amount to a count and associate it with that name
    //and adds it to a unique array with only unique names
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
    //prints out the output
    for (int i = 0; i < uniqueNames; i++)
    {
        printf("%s: %d\n", unique[i], uniqueCounter[i]);
    }
    return 0;
}