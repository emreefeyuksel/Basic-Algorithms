#include <stdio.h>

void reverser(char* star,char* revstar){
    int i=0;
    while(*star){
        star++;     i++;//Increasing index until the string is over (encountering '\0')
    }
    while(i>=0){
        star--;     *revstar=*star;//decreasing index and putting the value to reverse array
        i--;        revstar++;//using "i" as size and by increasing index of reverse array putting the chars in reverse order
    }
    *revstar='\0';
}
int main() {
        char string[50];      //defining sequence
        char revstr[50];
        char* star=string;
        char* revstar=revstr;
        printf("enter your word:");     //user sequence
        scanf("%s",string);
        reverser(star,revstar);     //function sequence
        printf("here is the reverse of it:%s",revstr);
        return 0;       //end of main
}
