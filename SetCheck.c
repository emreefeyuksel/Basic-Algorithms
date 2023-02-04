#include <stdio.h>
#include <stdbool.h>

int Uni[]={1,2,3,4,5,6,7,8,9,10};

void SetCheck(int Sub[],int size){
    bool a;
    for (int i = 0; i < size; ++i) {
        a=false;
        for (int j = 0; j < 10; ++j) {
            if(Sub[i]==Uni[j])
                a=true;
        }
        if(a==false)
            break;
    }
    if(a==true)
        printf("This set is Subset of Uni!\n");
    else
        printf("This set is not Subset of Uni!\n");
}
int main() {
    int B[]={1,2,3},size2=3;
    int C[]={8,98,10},size3=3;
    int D[]={11,56,78,65},size4=4;
    SetCheck(B,size2);
    SetCheck(C,size3);
    SetCheck(D,size4);
    return 0;
}
