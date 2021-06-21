#include<stdio.h>
#include<stdlib.h>
struct DLL{
    struct DLL *prev;
    int data;
    struct DLL *next;
};
typedef struct DLL *node;
node head,last;
node createNode(){
    node temp;
    temp=(node)malloc(sizeof(struct DLL));
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
void addNode(int value){
    node temp,p;
    temp=createNode();
    temp->data=value;
    if(head==NULL){
        head=temp;
        last=temp;
    }
    else{
        last->next=temp;
        temp->prev=last;
        last=temp;
    }
}
void insert(int pos,int value){
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
        last=temp;
    }
    else if(pos<=count+1&&pos>0&&count!=0){
        node temp;
        temp=createNode();
        temp->data=value;
        if(pos==count+1){
            last->next=temp;
            temp->prev=last;
            last=temp;
        }
        else if(pos==1){
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
        else{
            p=head;
            for(int i=1;i<pos;i++){
                p=p->next;
            }
            temp->prev=p->prev;
            p->prev->next=temp;
            p->prev=temp;
            temp->next=p;
        }
    }
    else{
        printf("\nInvalid position!\n\n");
    }
}
void deleteNode(int pos){
    node p;
    int count=1;
    if(head==NULL){
        count=0;
        printf("\nThe list is empty!\n");
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
            if(head==NULL){
                last=NULL;
            }
        }
        else if(pos==count){
            last=last->prev;
            free(last->next);
            last->next=NULL;
        }
        else{
            p=head;
            for(int i=1;i<pos;i++){
                p=p->next;
            }
            p->prev->next=p->next;
            p->next->prev=p->prev;
            free(p);
        }
    }
    else{
        printf("Please enter a valid position!\n\n");
    }
}
void printList(){
    node p;
    p=head;
    int i=0;
    while(p!=NULL){
        printf("List pos (%d):  %d\n",++i,p->data);
        p=p->next;
    }
}
void printLast(){
    node p;
    p=last;
    int i=0;
    while(p!=NULL){
        printf("List pos (%d) from end:  %d\n",++i,p->data);
        p=p->prev;
    }
}
void print(){
    printf("\n\nFrom Beg:\n\n");
    printList();
    printf("\n\nFrom Last:\n\n");
    printLast();
}
int main(){
    int x;
    head=NULL;
    last=NULL;
    printf("Enter the number of elements you wish to store in the linked list:\t");
    scanf("%d",&x);
    for(int i=0;i<x;i++){
        int n;
        printf("Enter the value at position %d:\t",i+1);
        scanf("%d",&n);
        addNode(n);
    }
    print();
    printf("Enter the position to insert 12:\t");
    scanf("%d",&x);
    insert(x,12);
    print();
    printf("Enter the position to delete:\t");
    scanf("%d",&x);
    deleteNode(x);
    print();
}