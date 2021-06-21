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
void add(int at[100][3],int bt[100][3],int tri[100][3]){
    int t1=at[0][2],t2=bt[0][2],i=0,j=0,k=0;
    tri[0][0]=at[0][0];
    tri[0][1]=at[0][1];
    while(i<=t1&&j<=t2){
        if(at[i][0]<bt[j][0]||(at[i][0]==bt[j][0]&&at[i][1]<bt[j][1])){
            tri[k][0]=at[i][0];
            tri[k][1]=at[i][1];
            tri[k][2]=at[i][2];
            k++;i++;
        }
        else if(bt[j][0]<at[i][0]||(bt[j][0]==at[i][0]&&bt[j][1]<at[i][1])){
            tri[k][0]=bt[j][0];
            tri[k][1]=bt[j][1];
            tri[k][2]=bt[j][2];
            k++;j++;
        }
        else{
            tri[k][0]=at[i][0];
            tri[k][1]=at[i][1];
            tri[k][2]=at[i][2]+bt[j][2];
            if(k>0)
            tri[0][2]-=1;
            k++;i++;j++;
        }
    }
    while(i<=t1){
        tri[k][0]=at[i][0];
        tri[k][1]=at[i][1];
        tri[k][2]=at[i][2];
        k++;i++;
    }
    while (j<=t2){
        tri[k][0]=bt[j][0];
        tri[k][1]=bt[j][1];
        tri[k][2]=bt[j][2];
        k++;j++;
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
void createMat(int tri[100][3],int res[50][50]){
    int n=1;
    for(int i=0;i<tri[0][2];i++){
        if(tri[n][2]!=0){
            res[tri[n][0]][tri[n][1]]=tri[n][2];
            n++;
        }
    }
    for(int i=0;i<tri[0][0];i++){
        for(int j=0;j<tri[0][1];j++){
            if(!(res[i][j]!=0)){
                res[i][j]=0;
            }
        }
    }
}
void printTri(int b[100][3]){
    printf("\nMatrix in triplet form --\n");
    for (int i = 0; i < b[0][2]+1; i++)
        printf("%d\t%d\t%d\n",b[i][0],b[i][1],b[i][2]);
}
int main(){
    int r1,c1,r2,c2,a[50][50],at[100][3],b[50][50],bt[100][3],res[50][50],tri[100][3];
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
    createTri(a,r1,c1,at);
    printMat(a,r1,c1);
    printTri(at);
    printf("\nEnter the elements of the sparse matrix 2: \n");
    enterMat(b,r2,c2);
    createTri(b,r2,c2,bt);
    printMat(b,r2,c2);
    printTri(bt);
    add(at,bt,tri);
    printf("\nResultant ");
    printTri(tri);
    printf("\nResultant ");
    createMat(tri,res);
    printMat(res,tri[0][0],tri[0][1]);
}