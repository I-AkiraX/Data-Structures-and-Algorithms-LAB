#include<stdio.h>
#include<stdlib.h>
void printMatrix(int *a,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        printf("%d\t",*(a+i*n+j));
        printf("\n");
    }
}
int formTriplet(int* a,int* trip,int m,int n){
    int count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(*(a+i*n+j)!=0)
            count++;
        }
    }
    printf("%d",count);
    if(count>=(m*n/2)) return 1;
    else{
        trip=(int*)calloc(3*(count+1),sizeof(int));
        *(trip+0)=m;
        *(trip+1)=n;
        *(trip+2)=count;
        int k=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(*(a+i*n+j)!=0){
                    *(trip+k*3)=i;
                    *(trip+k*3+1)=j;
                    *(trip+k*3+2)=*(a+i*n+j);
                    k++;
                }
            }
        }
        printMatrix(trip,count+1,3);
        return 0;
    }
}
void enterMatrix(int *a,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",(a+i*n+j));
        }
    }
}
int main(){
    int *mat;
    int *triplet=(int*)calloc(1,sizeof(int));
    int count=0;
    int m,n;
    char ch='y';
    while (ch=='y'){
        printf("Enter the number of rows of the first matrix:\t");
        scanf("%d",&m);
        printf("Enter the number of columns of the first matrix:\t");
        scanf("%d",&n);
        mat=(int*)calloc(m*n,sizeof(int));
        enterMatrix(mat,m,n);
        printMatrix(mat,m,n);
        if(formTriplet(mat,triplet,m,n)==1){
            printf("The entered matrix is not a sparse matrix!\nEnter 'y' and click enter to re-enter the matrix or enter anything else to exit:\t");
            scanf("%*c");
            scanf("%c",&ch);
        }
        else{
            printf("The sparse matrix in triplet form is given as follows:\n");
            printMatrix(triplet,*(triplet+2),3);
        }
    }
    
}