#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
* The program passes an array of 1000 integers to one of the functions that
* either looks for the smallest number and the location or shifts elements in a
* circular way.
*
* @authors Omar Yassin
* @version 4.3
*/
int arrayChange(int mainArray[]){
    int secondArray[1000];//init the secondArray with the size of 1000
    int lastNum=mainArray[999];//getting the last number of the array
    secondArray[0]=lastNum;//setting the first place of the array to the last number
    for (int i = 0; i < 1000; i++) {//printing the array before
        printf("%d ",mainArray[i]);;
    }

    printf("\n\n\n\n\n\n");
    for (int i = 1; i < 999; i++) {//adding elements from the mainArray to the secondArray
        secondArray[i]=mainArray[i];
    }

    for (int i = 0; i < 999; i++) {//printing the change
        printf("%d ",secondArray[i]);;
    }
    printf("\n");
}
int choice() {
    int inputNumber=0;
    printf("Welcome to the program\n");
    printf("choose 1 for getting the smallest number\n");//printing the choices
    printf("Choose 2 for circular shift \n");
    scanf("%d", &inputNumber);//getting the input
    return inputNumber;//returning the number
}

int smallest(int mainArray[]) {
    int smallestFound=mainArray[0], smallestPlace= 1000;//setting values to the variables
    for (int i=0,current = 0; i < 1000; i++) {
        current = mainArray[i];//getting the current number
        if (current<smallestFound) {//setting the smallest number and the smallest place
            smallestFound= current;
            smallestPlace= i;
        }
    }
    printf("the smallest number is %d and the place is %d \n",smallestFound,smallestPlace );
    return 0;
}

int main(int argc, char const *argv[]) {
    srand(time(0));//setting srand to time(0) to randomize the array everytime the code ran
    int mainArray[1000];// init the array
    int i,userChoice,loopNum;//init variables
    int size = 1000;// setting the size to 1000
    for (i = 0; i < size; i++) {//for loop to put random numbers in the array
        loopNum= rand() % 1000;//loopNum is a diffrent random number each iteration
        mainArray[i]= loopNum;//add it to the array
    }
    userChoice= choice();//setting user choiceNumber to the the choice from the user input
    if (userChoice==1) {//checking the user choice
        smallest(mainArray);//passing the array to the smallest function
    }
    else if(userChoice==2){//checking the user choice
        arrayChange(mainArray);//passing the array to the arrayChange function
    }else{//incorrect choice
        printf("re enter the choice \n");
        userChoice= choice();
    }

  return 0;
}
