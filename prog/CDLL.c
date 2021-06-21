#include<stdio.h>
#include<stdlib.h>
struct CDLL{
    int data;
    struct CDLL *next,*prev;
 };
typedef struct CDLL *node;
node head,last;
node createNode(){
    node temp;
    temp=(node)malloc(sizeof(struct CDLL));
    temp->next=temp;
    temp->prev=temp;
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
        temp->prev=last;
        head->prev=temp;
        last->next=temp;
        last=temp;
    }
}
void insert(int val,int pos){
    node p;
    int count=1;
    if(head==NULL)
        count=0;
    else{
        p=head;
        while(p->next!=head){
            p=p->next;
            count++;
        }
    }
    if(count==0&&pos==1){
        node temp,p;
        temp=createNode();
        temp->data=val;
        head=temp;
        last=temp;
    }
    else if(pos<=count+1&&pos>0&&count!=0){
        node temp,p;
        temp=createNode();
        temp->data=val;
        if(pos==count+1){
            temp->next=head;
            temp->prev=last;
            head->prev=temp;
            last->next=temp;
            last=temp;
        }
        else if(pos==1){
            temp->next=head;
            temp->prev=last;
            head->prev=temp;
            last->next=temp;
            head=temp;
        }
        else{
            p=head;
            for(int i=1;i<pos-1;i++){
                p=p->next;
            }
            temp->next=p->next;
            temp->prev=p;
            p->next->prev=temp;
            p->next=temp;
        }
    }
    else{
        printf("\nInvalid position\n\n");
    }
}
void deleteNode(int pos){
    node p;
    int count=1;
    if(head==NULL)
        count=0;
    else{
        p=head;
        while(p->next!=head){
            p=p->next;
            count++;
        }
    }
    if(pos<=count&&pos>0&&count!=0){
        if(pos==1){
            if(count==1){
                free(head);
                head=NULL;
                last=NULL;
            }
            else{
                node temp=head;
                head=head->next;
                last->next=head;
                head->prev=last;
                free(temp);
            }
        }
        else if(pos==count){
            node temp=last;
            last=last->prev;
            head->prev=last;
            last->next=head;
            free(temp);
        }
        else{
            p=head;
            for(int i=1;i<pos-1;i++){
                p=p->next;
            }
            node temp=p->next;
            p->next=temp->next;
            temp->next->prev=p;
            free(temp);
        }
    }
    else{
        printf("\nInvalid position.\n\n");
    }
}
print(){
    node p=head;
    if(head!=NULL){
        int i=0;
        while(p->next!=head){
            printf("pos %d:  %d\n",++i,p->data);
            p=p->next;
        }
        printf("pos %d:  %d\n",++i,p->data);
    }
}
int main(){
    head=NULL;
    last=NULL;
    int x;
    printf("Enter the number of elements:  ");
    scanf("%d",&x);
    for(int i=0;i<x;i++){
        int n;
        printf("Enter the value at position %d:  ",i+1);
        scanf("%d",&n);
        addNode(n);
    }
    print();
    printf("\nEnter the position to insert:  ");
    scanf("%d",&x);
    insert(12,x);
    print();
    printf("Enter the position to delete:\t");
    scanf("%d",&x);
    deleteNode(x);
    print();
}