#include <stdio.h>
void Process(int a) {
    int Can[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        if (a == Can[i]) {
            printf("True");
            break;
        }
        else if(i==4 && a!=Can[i]){
            printf("False");
        }}}
int main(){
    int x;
    printf("bir no gir bakim\n");
    scanf("%d",&x);
    Process(x);
    return 0;
}