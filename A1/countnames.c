#include <stdio.h>
int main(void)
{
    FILE *names;
    names = fopen("names.txt", "r");

    char uniqueNames[100][30];

    char line[30];
    while(NULL != fgets(line, 30, names))
    {
        printf("%s", line);
    }
    return 0;
}