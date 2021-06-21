#include<stdio.h>
void createTri(int a[50][50],int r,int c,int b[100][3]){
    int k=1;
    b[0][0]=r;
    b[0][1]=c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j]!=0){
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                k++;
            }
        }
    }
    b[0][2]=k-1;
}
void printTri(int b[100][3]){
    for (int i = 0; i < b[0][2]+1; i++)
        printf("%d\t%d\t%d\n",b[i][0],b[i][1],b[i][2]);
}
int main(){
    int r,c,a[50][50],b[100][3];
    printf("Enter the number of rows and coloumns: \n");
    scanf("%d%d",&r,&c);
    printf("\nEnter the elements of the sparse matrix: \n");
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%d",&a[i][j]);
    printf("\nSparse matrix in matrix form --\n");
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    createTri(a,r,c,b);
    printf("\nSparse matrix in triplet form --\n");
    printTri(b);
}