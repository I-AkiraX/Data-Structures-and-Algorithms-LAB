#include <stdio.h>
int main(){
    int i, j, a, size, number[300];
    printf("Enter the number of elements you would like to sort in ascending order:  ");
    scanf("%d",&size);
    printf("Enter the numbers-- \n");
    for (i=0;i<size;++i)
        scanf("%d", &number[i]);
    for (i = 0; i < size; ++i) {
        for (j=i+1;j<size;++j){
            if (number[i]>number[j]) {
                a=number[i];
                number[i]=number[j];
                number[j]=a;
            }
        }
    }
    printf("The numbers arranged in ascending order are given below--\n");
    for (i=0;i<size;++i)
        printf("%d\n",number[i]);
    return 0;
}