#include<stdio.h>
int del(int array[500],int n,int pos){
    if(pos>n||pos<1||n==0){
        printf("Position is out of scope.");
    }
    else{
            for(int i=pos-1;i<n-1;i++){
            array[i]=array[i+1];
        }
        n--;
        printf("The updated array is:\n");
        for(int i=0;i<n;i++)
            printf("%d\t",array[i]);
    }
    return n;
}
int main(){
    int n,array[500];
    printf("Enter the number of elements of the array:\t");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;++i)
        scanf("%d",&array[i]);
    printf("The entered array is:\n");
    for(int i=0;i<n;i++)
        printf("%d\t",array[i]);
    int pos;
    char con='x';
    printf("\n\nType 'y' to delete an element:\t");
    scanf("%*c");
    scanf("%c",&con);
    while(con=='y'&&n>0){
        printf("Enter the position of the element in the array:\t");
        scanf("%d",&pos);
        n=del(array,n,pos);
        printf("\n\nType 'y' to delete an element:\t");
        scanf("%*c");
        scanf("%c",&con);
    }
    if(n==0){
        printf("The Array is empty!");
    }
    return 0;
}