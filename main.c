#include <stdio.h>

char table[9];
int  selection(char p[],int turn){
    int choice;
    while(1){
    printf("%s make your decision\n1.Select Coordinate\n2.Surrender",p);
    scanf("%d",&choice);
    if(choice==2 && turn<2){
        printf("You cannot surrender at the 1st turn coward!");
        continue;
        }
    break;
    }
    return choice;
}
void introductbattlefield(){
    printf("You will use these coordinates to put X and O's\n");
    int k=0;
    for (int i = 0; i < 10; ++i) {
        printf("\t");
        for (int j = 0; j < 10; ++j) {
            if((j==1 || j==5 || j==9)&&(i==1 || i==5 || i==9))
                printf("%d",k++);
            else if(j==3 || j==7){
                printf("|");
            }
            else if(i==3 || i==7)
                printf("-");
            else
                printf(" ");
        }
        printf("\n");
    }
}
void Deploy(char sign,int coordinate){
    table[coordinate]=sign;
    int k=0;
    for (int i = 0; i < 10; ++i) {
        printf("\t");
        for (int j = 0; j < 10; ++j) {
            if((j==1 || j==5 || j==9)&&(i==1 || i==5 || i==9))
                printf("%c",table[k++]);
            else if(j==3 || j==7){
                printf("|");
            }
            else if(i==3 || i==7)
                printf("-");
            else
                printf(" ");
        }
        printf("\n");
    }
}
int Check(int cd){
    switch(cd){
        case 0:
            if((table[cd]==table[cd+3]&&table[cd]==table[cd+6])||(table[cd]==table[cd+1]&&table[cd]==table[cd+2])||(table[cd]==table[cd+4]&&table[cd]==table[cd+8])){
                return 1;}
            return 0;
        case 1:
            if((table[cd]==table[cd+3]&&table[cd]==table[cd+6])||(table[cd]==table[cd-1]&&table[cd]==table[cd+1])){
                return 1;}
            return 0;
        case 2:
            if((table[cd]==table[cd+3]&&table[cd]==table[cd+6])||(table[cd]==table[cd-1]&&table[cd]==table[cd-2])||(table[cd]==table[cd+2]&&table[cd]==table[cd+4])){
                return 1;}
            return 0;
        case 3:
            if((table[cd]==table[cd-3]&&table[cd]==table[cd+3])||(table[cd]==table[cd+1]&&table[cd]==table[cd+2])){
                return 1;}
            return 0;
        case 4:
            if((table[cd]==table[cd-3]&&table[cd]==table[cd+3])||(table[cd]==table[cd-1]&&table[cd]==table[cd+1])||(table[cd]==table[cd+2]&&table[cd]==table[cd-2])||(table[cd]==table[cd+4]&&table[cd]==table[cd-4])){
                return 1;}
            return 0;
        case 5:
            if((table[cd]==table[cd+3]&&table[cd]==table[cd-3])||(table[cd]==table[cd-1]&&table[cd]==table[cd-2])){
                return 1;}
            return 0;
        case 6:
            if((table[cd]==table[cd-3]&&table[cd]==table[cd-6])||(table[cd]==table[cd+1]&&table[cd]==table[cd+2])||(table[cd]==table[cd-2]&&table[cd]==table[cd-4])){
                return 1;}
            return 0;
        case 7:
            if((table[cd]==table[cd-3]&&table[cd]==table[cd-6])||(table[cd]==table[cd-1]&&table[cd]==table[cd+1])){
                return 1;}
            return 0;
        case 8:
            if((table[cd]==table[cd-3]&&table[cd]==table[cd-6])||(table[cd]==table[cd-1]&&table[cd]==table[cd-2])||(table[cd]==table[cd-4]&&table[cd]==table[cd-8])){
                return 1;}
            return 0;
        default:printf("how did you get there!!!");
    }
    return 0;
}
int cdselect(char p){
    int cd;
    while(1){
        printf("enter the coordinate that you want to deploy %c:",p);
        scanf("%d",&cd);
        printf("\n");
        if(table[cd]!='X' && table[cd]!='O'&& cd>-1 && cd<9)
            return cd;
        else
            printf("Invalid coordinate!");
    }
}
int main() {
    char p1[30],p2[30],P1Choice,P2Choice;
    int a,b=0,cd;
    printf("-Welcome to Tic-Tac-Toe game made by Emre Efe Yüksel-\n-Powered by Boring Chores-\n");
    printf("Insert the name of 1st Player:");
    gets(p1);
    printf("Insert the name of 2st Player:");
    gets(p2);
    printf("Let's start the mighty battle between %s and %s\n",p1,p2);
    introductbattlefield();
    printf("%s choose your sign that will carry you to victory or a horrible defeat -draw is possible btw-\n X OR O->->->->",p1);
    while(1){
    scanf("%c",&P1Choice);
    if(P1Choice=='X'){
        P2Choice='O';
        break;
    }
    else if(P1Choice=='O'){
        P2Choice='X';
        break;
    }
    else{
        printf("come on man just enter X or O!");
        scanf("%c",&P1Choice);}
    }
    for(int i=0;i<9 && b!=1;i++){
        if(i%2==0) {
            a=selection(p1,i);
            }
        else if(i%2==1) {
            a=selection(p2,i);
            }
        switch(a){
            case 1:
                if(i%2==0){
                    cd=cdselect(P1Choice);
                Deploy(P1Choice,cd);
                b=Check(cd);
                    if(b==1){
                    printf("%s WINS!",p1);
                    break;
                    }
                }
                else{
                    cd=cdselect(P2Choice);
                Deploy(P2Choice,cd);
                b=Check(cd);
                    if(b==1){
                    printf("%s WINS!",p2);
                    break;
                    }
                }
            case 2:
                break;
            default:
                printf(" Look at this site:https://www.clinical-partners.co.uk/for-adults/autism-and-aspergers/adult-autism-test ");
            }
    }
    if(b==0)
        printf("\nDraw!");
        printf("\n\n\n\n-GAME IS OVER-");
return 0;
}