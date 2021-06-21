#include<stdio.h>
#include<stdlib.h>
struct LinkedList{
    int data;
    struct LinkedList *next;
 };
 typedef struct LinkedList *node;
node createNode(){
    node temp;
    temp=(node)malloc(sizeof(struct LinkedList));
    temp->next=NULL;
    return temp;
}
node addNode(node head,int value){
    node temp,p;
    temp=createNode();
    temp->data=value;
    if(head==NULL){
        head=temp;
    }
    else{
        p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
    }
    return head;
}
void printList(node head){
    node p;
    p=head;
    int i=0;
    while(p!=NULL){
        printf("List pos (%d):  %d\n",++i,p->data);
        p=p->next;
    }
}
node insertBeg(node head,int value){
    node temp,p;
    temp=createNode();
    temp->data=value;
    if(head==NULL){
        head=temp;
    }
    else{
        temp->next=head;
        head=temp;
    }
    return head;
}
node insertMid(node head,int value,int pos){
    node p;
    int count=1;
    if(head==NULL){
        count=0;
    }
    else{
        p=head;
        while(p->next!=NULL){
            p=p->next;
            count++;
        }
    }
    if(count==0&&pos==1){
        node temp;
        temp=createNode();
        temp->data=value;
        head=temp;
    }
    else if(pos<=count+1&&pos>0&&count!=0){
        node temp;
        temp=createNode();
        temp->data=value;
        if(pos==count+1){
            p->next=temp;
        }
        else if(pos==1){
            temp->next=head;
            head=temp;
        }
        else{
            p=head;
            for(int i=1;i<pos-1;i++){
                p=p->next;
            }
            temp->next=p->next;
            p->next=temp;
        }
    }
    else{
        printf("The position is not valid!\n\n");
    }
    return head;
}
node deleteNode(node head,int pos){
    node p;
    int count=1;
    if(head==NULL){
        count=0;
        printf("\nThe list is empty!\n");
        return head;
    }
    else{
        p=head;
        while(p->next!=NULL){
            p=p->next;
            count++;
        }
    }
    if(pos<=count&&pos>0&&count!=0){
        if(pos==1){
            node temp=head;
            head=head->next;
            free(temp);
        }
        else if(pos==count){
            p=head;
            for(int i=1;i<count-1;i++){
                p=p->next;
            }
            free(p->next);
            p->next=NULL;
        }
        else{
            p=head;
            for(int i=1;i<pos-1;i++){
                p=p->next;
            }
            node temp=p->next;
            p->next=p->next->next;
            free(temp);
        }
    }
    else{
        printf("Please enter a valid position!\n\n");
    }
    return head;
}
void main(){
    node head;
    head=NULL;
    int x;
    printf("Enter the number of elements you wish to store in the linked list:\t");
    scanf("%d",&x);
    for(int i=0;i<x;i++){
        int n;
        printf("Enter the value at position %d:\t",i+1);
        scanf("%d",&n);
        head=addNode(head,n);
    }
    printList(head);
    int xa;
    printf("\n\nEnter a value:\t");
    scanf("%d",&xa);
    head=insertMid(head,12,xa);
    printList(head);
    printf("\n\nEnter a value:\t");
    scanf("%d",&xa);
    head=deleteNode(head,xa);
    printList(head);
}   