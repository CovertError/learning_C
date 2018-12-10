#include <stdio.h>
#include <string.h>
#include <ctype.h>

void OutputResult(char text[], int WORDLEN, int textLen) {
    int keep=0;
    char printArray[1000];//creating the print array to store everything that is going to be printed
    int lineKeep=0;
    for (int i = 0; i < textLen; i++) {// for loop to go oever the text
        if (isupper(text[i])) {//check if any of the letter as upper case
            if (i==0) {//check if the char is in the first place of the array
                while (text[i]!= '\n' && text[i]!= '\0') {//looping while the the place in array is not equal to a new line and nothing
                    printArray[i]=text[i];
                    lineKeep++;
                    i++;
                }
                printArray[i]='\n';
                i++;
                lineKeep++;
            }else{//if the place of the char is not in the first place
                while (keep==0) {//looping while keep is equal to 0
                    i--;
                    if (text[i]=='\n') {
                        keep=1;
                        i++;
                    }
                }
                while (keep==1) {
                    if (text[i]!='\n'&& i<=textLen) {//checking if the char is equal to a new line and i is less than or qual to the length of the text
                        printArray[lineKeep]=text[i];
                        lineKeep++;
                        i++;
                    }else{
                        keep=0;
                    }
                }
            }
        }
    }
    printf("%s\n",printArray);
    printf("%s\n",printArray);
}
void CapitalizeWords(char string[], char word[]){
    int i;
    int keep;
    int textLen = strlen(string);
    int WORDLEN = strlen(word);
    int edited=0;
    for (i=0;i<textLen;i++){
        if (isalpha(string[i]) && word[0] == string[i] ){//checking if the char is an alphabit and its equal to the first ltter in the word
            if (i==0 || string[i-1]== ' '||string[i-1]== '\n') {//checking if i is equal to 0 or there is a space or a line break before
                for (int j = 0; j < WORDLEN; j++) {
                    if (word[j]== string[i]) {// checking if the char is qual to the one in the word
                        string[i]= toupper(string[i]);
                        i++;
                        edited++;
                    }
                }
                if (edited != WORDLEN ) {//if the edited chars are not equal to amout of letter of the word if not change the chars back to small letters
                    keep=i;
                    while (edited != 0) {
                        i--;
                        edited--;
                        string[i]= tolower(string[i]);
                    }
                    i=keep;
                    edited=0;
                }
                edited=0;
            }
        }
    }
    OutputResult(string,WORDLEN,textLen);//callling the
}
int main(){
    char text[1000];
    char word[10];
    printf("Please enter the text when your done press tab and enter\n" );
    scanf("%[^\t]",text);
    printf("Please enter the word you are looking for:\n");
    scanf("%s", word);
    printf("\n\n" );
    printf("the output is \n" );
    CapitalizeWords(text, word);
    return 0;
}
