#include<stdio.h>
#include<stdlib.h>
struct CLL{
    int data;
    struct CLL *next;
 };
typedef struct CLL *node;
node head,last;
node createNode(){
    node temp;
    temp=(node)malloc(sizeof(struct CLL));
    temp->next=temp;
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
        temp->next=head;
        last->next=temp;
        last=temp;
    }
}
void insert(/*int pos,*/int value){
    node p;
    int count=1;
    if(head==NULL){
        count=0;
    }
    else{
        p=head;
        while(p->next!=head){
            p=p->next;
            count++;
        }
    }
    /*if(count==0&&pos==1){
        node temp;
        temp=createNode();
        temp->data=value;
        head=temp;
        last=temp;
    }
    else if(pos<=count+1&&pos>0&&count!=0){*/
        node temp;
        temp=createNode();
        temp->data=value;
        if(count == 0){
            head=temp;
            last=temp;
        }
        //if(pos==count+1){
        else{
            temp->next=head;
            last->next=temp;
            last=temp;
        }/*
        else if(pos==1){
            temp->next=head;
            head=temp;
            last->next=head;
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
        printf("\nInvalid position!\n\n");
    }*/
}
void deleteNode(/*int pos*/){
    node p;
    int count=1;
    if(head==NULL){
        count=0;
        printf("\nThe list is empty!\n");
    }
    else{
        p=head;
        while(p->next!=head){
            p=p->next;
            count++;
        }
    }
    if(count>1){
        for(int i=0;i<count-1;i++){
            p=p->next;
        }
        free(last);
        last=p;
        last->next=head;
    }
    else if(count == 1){
        head = NULL;
        last = NULL;
    }
    /*if(pos<=count&&pos>0&&count!=0){
        if(pos==1){
            if(count==1){
                node temp=head;
                head=NULL;
                last=NULL;
                free(temp);
            }
            else{
                node temp=head;
                head=head->next;
                last->next=head;
                free(temp);
            }
        }
        else if(pos==count){
            p=head;
            for(int i=1;i<pos-1;i++){
                p=p->next;
            }
            for(int i=0;i<count-1;i++){
                p=p->next;
            }
            free(last);
            last=p;
            last->next=head;
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
    }*/
}
void print(){
    node p=head;
    if(head!=NULL){
        int i=0;
        while(p->next!=head){
            printf("Circular list pos (%d):  %d\n",++i,p->data);
            p=p->next;
        }
        printf("Circular list pos (%d):  %d\n",++i,p->data);
    }else
        printf("List is empty!");
}
int main(){
    head=NULL;
    last=NULL;
    int x, choice;
    begin:
    printf("\nPress--\n1: To create a list.\n2: To display list.\n3: Insertion at end.\n4: Deletion at end.\n5: To exit.\nYour choice:  ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter the number of elements you wish to store in the linked list:\t");
            scanf("%d",&x);
            for(int i=0;i<x;i++){
                int n;
                printf("Enter the value at position %d:\t",i+1);
                scanf("%d",&n);
                addNode(n);
            }
            goto begin;
        case 2:
            print();
            goto begin;
        case 3:
            printf("Enter the value to be inserted:  ");
            scanf("%d",&x);
            insert(x);
            goto begin;
        case 4:
            deleteNode();
            goto begin;
        case 5:
            exit(0);
        default:
            printf("Invalid!");
            goto begin;
    }
}