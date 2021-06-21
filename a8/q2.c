//queue implementation using stack

#include <stdio.h>
#include <stdlib.h>
int st1[100], st2[100];
int top1 = -1, top2 = -1;
int count = 0;
void push1(int data){
    st1[++top1] = data;
}
void push2(int data){
    st2[++top2] = data;
}
int pop1(){
    return(st1[top1--]);
}
int pop2(){
    return(st2[top2--]);
}
void enqueue(){
    int data, i;
    printf("Enter data into queue:  ");
    scanf("%d", &data);
    push1(data);
    count++;
}
void dequeue(){
    int i;
    for (i = 0;i <= count;i++){
        push2(pop1());
    }
    pop2();
    count--;
    for (i = 0;i <= count;i++){
        push1(pop2());
    }
}
void display(){
    int i;
    for (i = 0;i <= top1;i++){
        printf(" %d ", st1[i]);
    }
}
void create(){
    top1 = -1;top2 = -1;
}
int main()
{
    int ch;
    printf("\n\n1 - Enqueue element into queue\n2 - Dequeue element from queue\n3 - Display from queue\n4 - Exit\nEnter choice:  ");
    scanf("%d", &ch);
    create();
    while (1){
        switch (ch){
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice");
        }
        printf("\n\n1 - Enqueue element into queue\n2 - Dequeue element from queue\n3 - Display from queue\n4 - Exit\nEnter choice:  ");
        scanf("%d", &ch);
    }
}