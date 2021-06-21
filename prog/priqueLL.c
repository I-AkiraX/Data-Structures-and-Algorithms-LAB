//  C Program to implement priority queue using linked list

#include<stdio.h>
struct node{
    int priority,info;
    struct node *link;
}*front=NULL;
void insert(int item,int pri){
    struct node *tmp,*p;
    tmp=(struct node *)malloc(sizeof(struct node));
    if(tmp==NULL){
        printf("\nMemory not available\n");
        return;
    }
    tmp->info=item;
    tmp->priority=pri;
    if( isEmpty() || pri < front->priority ){
        tmp->link=front;
        front=tmp;
    }
    else{
        p = front;
        while( p->link!=NULL && p->link->priority<=pri )
            p=p->link;
        tmp->link=p->link;
        p->link=tmp;
    }
}
int del(){
    struct node *tmp;
    int item;
    if( isEmpty() ){
        printf("\nQueue Underflow\n");
        exit(0);
    }
    else{
        tmp=front;
        item=tmp->info;
        front=front->link;
        free(tmp);
    }
    return item;
}
void display(){
    struct node *ptr;
    ptr=front;
    if( isEmpty() )
        printf("\nQueue is empty\n");
    else{
        printf("\nQueue is :\n");
        printf("\nPriority       Item\n");
        while(ptr!=NULL){
            printf("%5d        %5d\n",ptr->priority,ptr->info);
            ptr=ptr->link;
        }
    }
}
int isEmpty(){
    if( front == NULL )
        return 1;
    else
        return 0;
}
int main(){
    int choice,item,pri;
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Quit\nYour choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nInput the item to be added in the queue : ");
                scanf("%d",&item);
                printf("\nEnter its priority : ");
                scanf("%d",&pri);
                insert(item, pri);
                break;
            case 2:
                printf("\nDeleted item is %d\n",del());
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default :
                printf("\nWrong choice\n");
        }
    }
    return 0;
}