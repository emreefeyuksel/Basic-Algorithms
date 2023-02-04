#include <stdio.h>

//A program that puts all even numbers to the left of the array and all odd numbers to right of the array.

void levenrodd(int arr[],int size){
    for (int i = 0; i < size; ++i) {
        if(arr[i]%2==0){
            int j=i;
            while(j>0){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
                j--;
            }
        }
    }
}

int main() {
    int size,arr[20];

    printf("enter the size:");
    scanf("%d",&size);

    for (int i = 0; i < size; ++i) {
        printf("enter number:");
        scanf("%d",&arr[i]);
    }

    levenrodd(arr,size);
    for (int i = 0; i < size; ++i) {
        printf("%d ",arr[i]);
    }
    return 0;
}
