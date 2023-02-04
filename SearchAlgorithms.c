#include <stdio.h>


void sort(int arr[],int size){
    int temp;
    for (int i = 0; i < size-1; ++i) {
        for (int j = 0; j < size-1-i; ++j) {
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }}}
    for (int i = 0; i < size; ++i) {
        printf("%d ",arr[i]);
    }
}
//Binary Search
int Bsearch(int arr[],int low,int high,int n){
    int mid = low + (high - low) / 2;
    if(high>=low){
        if(arr[mid]==n)
            return mid;
        else if(arr[mid]<n)
            return Bsearch(arr,mid+1,high,n);
        else
            return Bsearch(arr,low,mid-1,n);
    }
    return -1;
}
//Linear Search
int Lsearch(int arr[],int size,int n){
    sort(arr,size);
    int i;
    for(i=0;i<size;i++){
        if(arr[i]>=n)
            break;
    }
    if(arr[i]==n)
        return i;
    else
        return -1;
}

int main() {
    int n,size=15,arr[]={5,5,4,8,6,5,1,23,1,4,8,66,4,1,13};
    printf("Hello, please enter the number you want to search:\n");
    scanf("%d",&n);
    sort(arr,size);
    int a=Bsearch(arr,0,size-1,n);
    if(a==-1)
        printf("\nvalue not found!");
    else
        printf("value found at index:%d",a);
    return 0;
}
