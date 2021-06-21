//queue implementation using LL

#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *ptr;
}*front,*rear,*temp,*front1;

int count = 0;

void enq(int data) {
    if (rear == NULL){
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else{
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;
        rear = temp;
    }
    count++;
}

void deq(){
    front1 = front;
    if (front1 == NULL){
        printf("\nUnderflow condition!\n");
        return;
    }
    else
        if (front1->ptr != NULL){
            front1 = front1->ptr;
            printf("\nDequed value: %d\n", front->info);
            free(front);
            front = front1;
        }
        else{
            printf("\nDequed value: %d\n", front->info);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}

void display(){
    front1 = front;
    if ((front1 == NULL) && (rear == NULL)){
        printf("\nQueue is empty.\n");
        return;
    }
    while (front1 != rear){
        printf("%d ", front1->info);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d", front1->info);
}

void create() {
    front = rear = NULL;
}

int main(){
    int no, ch, e;
    create();
    while (1){
        printf("\nPress--\n1: Enque\n2: Deque\n3: Display\n4: Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch){
        case 1:
            printf("\nEnter data: ");
            scanf("%d", &no);
            enq(no);
            break;
        case 2:
            deq();
            break;
        case 3:
            printf("\n\nThe queue is--\n");
            display();
            printf("\n");
            break;
        case 4:
            exit(0);
        default:
            printf("\nWrong choice!");
            break;
        }
    }
}