#include<stdio.h>
#include<stdlib.h>
struct NODE{
    int number;
    struct NODE* next;
};
typedef struct NODE* node;
node createNode(){
    node temp;
    temp = (node) malloc(sizeof(struct NODE));
    temp->next = NULL;
    return temp;
}
node nextNode(node head,int data){
    node temp = createNode();
    temp->number = data;
    if(head == NULL){
        head = temp;
    }
    else{
        node p = head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next = temp;
    }
    return head;
}
void print(node head){
    node p = head;
    while(p!=NULL){
        printf("%d\t",p->number);
        p=p->next;
    }
}
int findPos(node head,int data){
    int count = 0,x = 1;
    node p = head;
    while(p!=NULL){
        count++;
        if(p->number==data){
            x=0;
            break;
        }
        p=p->next;
    }
    if(x==0){
        return count;
    }
    else{
        return -1;
    }
}
int main(){
    node head=NULL;
    char c=1;
    int data;
    while(c==1){
        printf("Enter a data:\t");
        scanf("%d",&data);
        head = nextNode(head,data);
        printf("\nEnter 1 to enter the next node. Enter anything else to stop entering:\t");
        scanf("%d",&c);
    }
    printf("Data in linked list:\t");
    print(head);
    printf("\n\nEnter a number to find in the linked list:\t");
    scanf("%d",&data);
    int pos = findPos(head,data);
    if(pos == -1){
        printf("Data not found!");
    }
    else{
        printf("Data found at:\tposition %d",pos);
    }
}