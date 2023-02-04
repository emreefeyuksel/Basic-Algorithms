#include <stdio.h>
#include <math.h>
#define size 10
/*A program that finds the standart deviation of the array taken from the user*/
float calSD(int arr[size]){
    float sum=0,varsum=0;
      for (int i=0;i<size;i++){
          sum+=arr[i];
      }
    float avg=sum/size;
    for (int i=0;i<size;i++){
        varsum+=pow((arr[i]-avg),2);
    }
    return sqrt(varsum/size);
}
int main( )
{   int arr[size];
    printf("Please enter %d numbers to calculate Standart deviation of them.\n",size);
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nStandart Deviation = %f",calSD(arr));
    return 0;
}
