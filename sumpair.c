#include <stdio.h>

int arr[]={9,2,8,5,1,6,7,4,3};
int size=9;
/*A program that finds pairs in the array which equals to the target number*/
void print_arr(){
    for (int i = 0; i < size; ++i) {
        printf("%d ",arr[i]);
    }
}

void find_pair(int x){
    int k=0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if((arr[i]+arr[j])==x && i!=j){
                k++;
                printf("%d. pair:[%d,%d]\n",k,arr[i],arr[j]);
            }
        }
    }
    if(k==0){printf("pair not found!");}
}
int main() {
    int target;
    print_arr();
    printf("\nInsert the target to find pairs.");
    scanf("%d",&target);
    find_pair(target);
    return 0;
}
