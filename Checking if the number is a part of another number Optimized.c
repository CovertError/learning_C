/*
Second HomeWork

Author: Omar Yassin
*/
#include <stdio.h>
#include <math.h>
#include <time.h>

int main () {
  char input1[20];
  char input2[19];
  double time_spent=0;

  printf("Enter the first number(BIG):\n");
  scanf("%s", &input1);

  printf("Enter the second number(Small):\n");
  scanf("%s", &input2);

  clock_t begin = clock();
  if (strstr(input1, input2)) {
    printf("%s is included in %s\n",input2,input1);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time elpased is %f seconds\n", time_spent);
  } else {
    printf("%s is not included in %s\n",input2,input1);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time elpased is %f seconds\n", time_spent);
  }


  return 0;
}
