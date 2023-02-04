#include <stdio.h>

void printarr(int arr[],int size){
    for (int i = 0; i < size; ++i) {
        printf("%d ",arr[i]);
    }
}
void swap(int*p,int*q){
    int temp=*q;
    *q=*p;
    *p=temp;
}
void selection_sort(int arr[],int size){
    for (int step=0;step<size-1;step++){
        int dex=step;
        for(int i=step + 1; i < size; i++){
            if(arr[i]<arr[dex])
                dex=i;
        }
        swap(&arr[dex],&arr[step]);
    }
}
void bubble_sort(int arr[],int size){
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-1-i; j++) {
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
void insertion_sort(int arr[],int size){
    for(int i=1;i<size;i++){
        int key=arr[i];
        int j=i-1;
        while (key < arr[j] && j >= 0) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
void shellSort(int array[], int n) {
    for (int interval = n / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i += 1) {
            int temp = array[i];
            int j;
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
    }
}
void merge_sort(int L[],int M[],int n1,int n2){
    bubble_sort(L,n1);
    bubble_sort(M,n2);
    int i=0,j=0,k=0;
    int arr[n1+n2];
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
    for (int l = 0; l < n1+n2; ++l) {
        printf("%d ",arr[l]);
    }
}
void quick_sort(int arr[],int low,int high){
    if(low>=high)
        return;
    int i,j,pivot,temp;
    pivot=arr[low];
    i=low+1;
    j=high;
    while(i<=j){
        while(arr[i]<=arr[pivot]&&i<high)
            i++;
        while(arr[j]>=arr[pivot]&&j>low)
            j--;

    if(i<j){
        swap(&arr[i],&arr[j]);
    }
    else
        break;
    }
    temp=pivot;
    pivot=arr[j];
    arr[j]=temp;

    quick_sort(arr,low,j-1);
    quick_sort(arr,j+1,high);
}
int main() {
    int arr1[]={0,3,10,5,1,9,8,0,1,7};
    int arr2[]={2,4,5,6,1,5,3,3,8};
    int size1=10,size2=9;

    //selection sort
    selection_sort(arr2,size2);
    printf("\nselection:");
    printarr(arr2,size2);

    //bubble sort
    bubble_sort(arr2,size2);
    printf("\nbubble   :");
    printarr(arr2,size2);

    //insertion sort
    insertion_sort(arr2,size2);
    printf("\ninsertion:");
    printarr(arr2,size2);

    //shell sort
    shellSort(arr2,size2);
    printf("\nshell    :");
    printarr(arr2,size2);

    //merge sort
    printf("\nmerge    :");
    merge_sort(arr1,arr2,size1,size2);

    //quick sort
    printf("\nquick    :");
    quick_sort(arr2,0,size2-1);
    printarr(arr2,size2);

    return 0;
}
