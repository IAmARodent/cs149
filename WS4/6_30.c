#include <stdio.h>

int MaxNumber(int num1, int num2, int num3, int num4)
{
   int max = num1;
   if(max < num2)
   {
      max = num2;
   }
   if(max < num3)
   {
      max = num3;
   }
   if(max < num4)
   {
      max = num4;
   }
   return max;
}

int MinNumber(int num1, int num2, int num3, int num4)
{
   int min = num1;
   if(min > num2)
   {
      min = num2;
   }
   if(min > num3)
   {
      min = num3;
   }
   if(min > num4)
   {
      min = num4;
   }
   return min;
}
int main(void) {
   int numbers[4];
   for(int i = 0; i < 4; i++)
   {
      scanf("%d", &numbers[i]);
   }
   printf("Maximum is %d\n", MaxNumber(numbers[0], numbers[1], numbers[2], numbers[3])); 
   printf("Minimum is %d\n", MinNumber(numbers[0], numbers[1], numbers[2], numbers[3]));

   return 0;
}
