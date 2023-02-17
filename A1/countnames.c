#include <stdio.h>
int main(void)
{
    FILE *names;
    names = fopen("names.txt", "r");

    char uniqueNames[100][30];

    char line[30];
    char emptyString[] = "\n";
    int nameCounter = 0;
    while(NULL != fgets(line, 30, names))
    {
        if(strcmp(line, emptyString) == 0)
        {
            printf("Line %d empty.\n", nameCounter+1);
        }
        strcpy(uniqueNames[nameCounter], line);
        nameCounter++;
    }
    for(int i = 0; i < nameCounter; i++)
    {
        printf("%s", uniqueNames[i]);
    }
    return 0;
}