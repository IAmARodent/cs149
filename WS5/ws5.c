/**
 * Description: Program that prints a string from multiple proceses
 * Author names: Geronimo A
 * Last modified date: 3/6/2023
 * Creation date: 3/6/2023
 */
#include <stdio.h>
#include <unistd.h>
/**
 * Main function that prints a string from multiple proceses
 */
int main(void)
{
    fork();
    fork();
    printf("hello world from PID: %d\n", getpid());
    return 0;
}
