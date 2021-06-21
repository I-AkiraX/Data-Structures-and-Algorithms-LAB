#include<stdio.h>
struct Book{
    int bookNo;
    double price;
    char name[50];
}B[5];
void highPrice( struct Book x[5]){
    int index=0;
    double large=x[0].price;
    for(int i=1;i<5;i++){
        if(large<x[i].price){
            large=x[i].price;
            index=i;
        }
    }
    printf("\n\nBook with Highest Price:\nName:\t%s\nBook Number:\t%d\nPrice:\t%.2lf",B[index].name,B[index].bookNo,B[index].price);
}
int main(){
    for(int i=0;i<5;i++){
        printf("\n\nBook %d:\nName:\t",i+1);
        scanf("%[^\n]s",B[i].name);
        printf("Book Number:\t");
        scanf("%d",&B[i].bookNo);
        printf("Price:\t");
        scanf("%lf",&B[i].price);
        scanf("%*c");
    }
    highPrice(B);
    return 0;
}