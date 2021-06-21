//queue implementation using array

#include <stdio.h>
#include<stdlib.h>
#define MAX 50
void insert();
void deleteq();
void display();
int queue_array[MAX],rear = - 1,front = - 1;
int main(){
    int choice;
    while (1){
        printf("\nPress--\n1.Insert element to queue\n2.Delete element from queue\n3.Display all elements of queue\n4.Quit\nYour choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                deleteq();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong choice\n");
        }
    }
}
void insert(){
    int item;
    if(rear == MAX - 1)
        printf("\nQueue Overflow\n");
    else{
        if(front== - 1)
            front = 0;
        printf("\nInsert the element in queue : ");
        scanf("%d", &item);
        rear = rear + 1;
        queue_array[rear] = item;
    }
}
void deleteq(){
    if(front == - 1 || front > rear){
        printf("\nQueue Underflow\n");
        return;
    }
    else{
        printf("\nElement deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
}
void display(){
    int i;
    if(front == - 1)
        printf("\nQueue is empty\n");
    else{
        printf("\nQueue is : \n");
        for(i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
            printf("\n");
    }
}