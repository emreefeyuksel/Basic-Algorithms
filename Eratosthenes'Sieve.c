#include <stdio.h>
#define N 200
/*Eratosthenes' Algorithm Implementation with arrays*/
int main() {
    int arr[N];
    int p=1;
    while(p<N){
        p++;
        int j=2*p;
        while(j<N) {
            arr[j]=1;
            j+=p;
        }
    }
    for (int i = 2; i < N; ++i) {
        if(arr[i]!=1)
            printf("%d ",i);
    }
    return 0;
}
