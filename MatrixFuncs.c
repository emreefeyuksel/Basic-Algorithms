#include <stdio.h>
#define Maxrow 10
#define Maxcol 10
#define Frame 36

/*Doing some rotating-sorting operations with an array of 100 integers*/

void readMatrix(int matrix[Maxrow][Maxcol]){
    printf("please enter the matrix numbers\n");
    for(int i=0;i<Maxrow;i++){
        for(int j=0;j<Maxcol;j++){
            scanf("%d",&matrix[i][j]);
        }}
}
void rotate(int matrix[Maxrow][Maxcol]){
    int temparr[Maxrow][Maxcol];
    for(int i=0;i<Maxrow;i++){
        for(int j=0;j<Maxcol;j++){
            temparr[i][j]=matrix[i][j];
        }}
    for(int i=0;i<Maxrow;i++){
        for(int j=0;j<Maxcol;j++){
            matrix[j][Maxcol-1-i]=temparr[i][j];
        }}
}
void sortRow(int matrix[Maxrow][Maxcol], int row){
    for(int i=0;i<Maxrow-1;i++){
        for(int j=0;j<Maxrow-1-i;j++){
            if(matrix[row][j]>matrix[row][j+1]){
                int temp=matrix[row][j];
                matrix[row][j]=matrix[row][j+1];
                matrix[row][j+1]=temp;
            }}}
}
void sortCol(int matrix[Maxrow][Maxcol], int col){
    for(int i=0;i<Maxcol-1;i++){
        for(int j=0;j<Maxcol-1-i;j++){
            if(matrix[j][col]>matrix[j+1][col]){
                int temp=matrix[j][col];
                matrix[j][col]=matrix[j+1][col];
                matrix[j+1][col]=temp;
            }}}
}
void clearFrame(int matrix[][10]){
    for(int i=0;i<Maxrow;i++){
        for(int j=0;j<Maxcol;j++){
            if(i==0||j==0||i==9||j==9){
                matrix[i][j]=0;
            }}}
}
void sortFrame(int matrix[][10]){
    int temparr[Frame],k=0,t=0,temp;
    for(int i=0;i<Maxrow;i++){          //putting frame numbers in a temporary array
        for(int j=0;j<Maxcol;j++){
            if(i==0||j==0||i==9||j==9){
                temparr[t]=matrix[i][j];  t++;
            }}}
    for(int i=0;i<Frame-1;i++){         //bubble sort
        for(int j=0;j<Frame-1-i;j++){
            if(temparr[j]>temparr[j+1]){
                temp=temparr[j];
                temparr[j]=temparr[j+1];
                temparr[j+1]=temp;
            }}}
        for(int j=0;j<Maxcol;j++){      //upper row
                matrix[0][j]=temparr[k];  k++;}
        for(int j=1;j<Maxcol-1;j++){    //right side
                matrix[j][9]=temparr[k];  k++;}
        for(int j=Maxcol-1;j>0;j--){    //bottom row
                matrix[9][j]=temparr[k];  k++;}
        for(int j=Maxcol-1;j>0;j--){    //left side
                matrix[j][0]=temparr[k];  k++;}
}
void printMatrix(int matrix[Maxrow][Maxcol]){
    printf("Matrix:\n");
    for(int i=0;i<Maxrow;i++){
        for(int j=0;j<Maxcol;j++){
            printf("\t%d",matrix[i][j]);
        }printf("\n");}
}
int main() {
    int matrix[10][10];
    readMatrix(matrix);
    printMatrix(matrix);
    rotate(matrix);printf("Rotated ");
    printMatrix(matrix);
    sortRow(matrix,4-1);
    sortRow(matrix,7-1);printf("4th And 7th Row Sorted ");
    printMatrix(matrix);
    sortCol(matrix,2-1);
    sortCol(matrix,5-1);printf("2nd And 5th Col Sorted ");
    printMatrix(matrix);
    sortFrame(matrix);printf("Frame Sorted ");
    printMatrix(matrix);
    clearFrame(matrix);printf("Frame Cleared ");
    printMatrix(matrix);
    return 0;
}
