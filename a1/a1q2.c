#include<stdio.h>
int insert(int array[500],int n,int pos,int ele){
    if(pos-1>n||pos<1||n==500){
        printf("Position is out of scope.");
    }
    else{
            for(int i=n;i>pos-1;i--){
            array[i]=array[i-1];
        }
        n++;
        array[pos-1]=ele;
        printf("The updated array is:\n");
        for(int i=0;i<n;i++)
            printf("%d\t",array[i]);
    }
    return n;
}
int main(){
    int n,array[500];
    printf("Enter the number of elements in the array:\t");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;++i)
        scanf("%d",&array[i]);
    printf("The entered array is:\n");
    for(int i=0;i<n;i++)
        printf("%d\t",array[i]);
    int pos,ele;
    char con='x';
    printf("\n\nType 'y' to insert an element:\t");
    scanf("%*c");
    scanf("%c",&con);
    while(con=='y'&&n<500){
        printf("Enter the position of the array:\t");
        scanf("%d",&pos);
        printf("Enter the element to insert in position %d:\t",pos);
        scanf("%d",&ele);
        n=insert(array,n,pos,ele);
        printf("\n\nType 'y' to insert an element:\t");
        scanf("%*c");
        scanf("%c",&con);
    }
    if(n==500){
        printf("The Array is full!");
    }
    return 0;
}