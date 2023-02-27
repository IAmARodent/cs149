/**
 * Description: Program tthat gets laps and returns the number of miles via functions.
 * Author names: Geronimo A
 * Last modified date: 2/21/2023
 * Creation date: 2/21/2023
 */
#include <stdio.h>
/**
 * Function that calculates amount of miles given laps.
 * Parameter: userLaps - amount of laps ran
 * Return: miles ran
*/
double LapsToMiles(double userLaps)
{
    return userLaps * 0.25;
}
/**
 * Main function that gets laps and returns the number of miles via functions.
*/
int main(void)
{
    double laps;
    scanf("%lf", &laps);
    printf("%0.2lf\n", LapsToMiles(laps));
    return 0;
}
