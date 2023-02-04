#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100

char exp[MAX];
char arr[MAX];
int top;

bool scan(){
    bool a;
    //stacking left parenthesis
    for(int i=0;i<strlen(exp);i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            top++;
            arr[top] = exp[i];
        }
    }
    //scanning
    for(int i=0;i<strlen(exp);i++){
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if(exp[i]==')'){
                if(arr[top]=='('){
                    top--;
                    a=true;
                }
                else
                    a=false;
            }
            else if(exp[i]=='}'){
                if(arr[top=='{']){
                    top--;
                    a=true;
                }
                else
                    a=false;
            }
            else if(exp[i]==']'){
                if(arr[top=='[']){
                    top--;
                    a=true;
                }
                else
                    a=false;
            }
        }
    }
    return a;
}
int main() {
    printf("write an expression with parenthesis");
    gets(exp);
    top=-1;

    bool a=scan();
    if(a==false)
        printf("\nExpression is not valid!");
    else
        printf("\nExpression is valid!");
    return 0;
}
