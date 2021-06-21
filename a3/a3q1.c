#include<stdio.h>
#include<stdlib.h>
int main(){
    int *p,n,i;
    printf("Enter the limit:  ");
    scanf("%d",&n);
    p=(int*) malloc(n*sizeof(int));
    printf("Enter %d numbers:\n",n);
    for ( i = 0; i < n; i++)
        scanf("%d",(p+i));
    for ( i = 0; i < n; i++)
        printf("%d ",*(p+i));
    printf("\nArray in reverse order:\n");
    for ( i = n-1; i >= 0 ; i--)
        printf("%d ",*(p+i));
}