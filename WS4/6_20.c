#include <stdio.h>
 
double LapsToMiles(double userLaps)
{
   return userLaps*0.25;
}

int main(void) 
{
   double laps;
   scanf("%lf", &laps);
   printf("%0.2lf\n", LapsToMiles(laps));
   return 0;
}
