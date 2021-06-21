#include<stdio.h>
void enterMat(int a[50][50],int r, int c){
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%d",&a[i][j]);
}
void printMat(int a[50][50],int r,int c){
    printf("\nSparse matrix in matrix form --\n");
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void add(int a[50][50],int b[50][50],int res[50][50],int r1,int c1){
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++){
            res[i][j]=a[i][j]+b[i][j];
        }
    }
}
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
    int r1,c1,r2,c2,a[50][50],b[50][50],res[50][50],tri[100][3];
    printf("Enter the number of rows and coloumns of matrix 1: \n");
    scanf("%d%d",&r1,&c1);
    printf("Enter the number of rows and coloumns of matrix 2: \n");
    scanf("%d%d",&r2,&c2);
    while(r1!=r2||c1!=c2){
        printf("\nMatrices can not be added!\n");
        printf("Enter the number of rows and coloumns of matrix 1: \n");
        scanf("%d%d",&r1,&c1);
        printf("Enter the number of rows and coloumns of matrix 2: \n");
        scanf("%d%d",&r2,&c2);
    }
    printf("\nEnter the elements of the sparse matrix 1: \n");
    enterMat(a,r1,c1);
    printMat(a,r1,c1);
    printf("\nEnter the elements of the sparse matrix 2: \n");
    enterMat(b,r2,c2);
    printMat(b,r2,c2);
    add(a,b,res,r1,c1);
    createTri(res,r1,c1,tri);
    printf("\nResultant matrix in triplet form--\n");
    printTri(tri);
}