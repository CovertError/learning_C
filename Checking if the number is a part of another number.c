/*
Second HomeWork

Author: Omar Yassin
*/
# include <stdio.h>
#include <time.h>

int main()
{
 double time_spent=0;
 int firstNum,secondNum,tempFirst,tempSecond,a;
 printf("please enter the first number(Small)\n");
 scanf("%i",&firstNum);
 printf("please enter the second number(BIG)\n");
 scanf("%i",&secondNum);
 clock_t begin = clock();
 tempFirst=firstNum;
 tempSecond=secondNum;
 a=1;
 // Finding out the number of digits in the socondNum
 while ( secondNum != 0 )
 {
   secondNum=secondNum/10;
   a=a*10;
 }

// making sure if the second number is part of the first one
 while (tempFirst != 0 )
 {
   if (tempFirst%a == tempSecond )
   {
    printf("%i is part of %i\n",tempSecond,firstNum);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time elpased is %f seconds\n", time_spent);
    break;
   }
   tempFirst=tempFirst/10;
 }

if (tempFirst == 0)
{
 printf("%i is not part of %i\n",tempSecond,firstNum);
 clock_t end = clock();
 time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 printf("Time elpased is %f seconds\n", time_spent);
}
}
