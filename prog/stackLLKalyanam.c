//SECTION Stack aur LL ka kalyanam

#include<stdio.h>
#include<stdlib.h>

struct NODE
{
    int key;
    struct NODE *next;
};
typedef struct NODE *node;

//SECTION LL ka janm
node createNode(){
    node temp;
    temp = (node)malloc(sizeof(struct NODE));
    temp->next = NULL;
    return temp;
}
node creatLL(node root,node temp){
    
    if(root==NULL)
    root = temp;
    else{
        root->next = creatLL(root->next,temp);
    }
    return root;
}
//!SECTION LL ka janm

//SECTION stack waala chutiyapa using LL

void push(node *top,node *head){
    node p1,p;
    if(*head!=NULL){
        p1 = *head;
        if(p1->next!=NULL){
            while(p1->next->next!=NULL){
                p1 = p1->next;
            }
            p = p1->next;
            p1->next = NULL;
        }
        else{
            p=p1;
            *head=NULL;
        }
        p->next = *top;
        *top = p;
    }
    else{
        printf("\n\nThe Linked List is empty!");
    }
}

void pop(node *top,node *head){
    node p;
    if(*top!=NULL){
        p = *top;
        *top = p->next;
        p->next = NULL;
        *head = creatLL(*head,p);
    }
    else{
        printf("Stack is empty!");
    }
}

//!SECTION stack waala chutiyapa using LL

//ANCHOR print
void printNodes(node start){
    node p = start;
    while(p!=NULL){
        printf("%d\t\t",p->key);
        p = p->next;
    }
}

//ANCHOR Driver code
int main(){
    node head = NULL;
    char check = 'y';
	while (check == 'y')
	{
		int key;
		printf("Enter a number to store in BST:\t");
		scanf("%d", &key);
        node temp = createNode();
        temp->key = key;
		head = creatLL(head, temp);
		printf("Enter 'y' to continue entering:  ");
        scanf("%*c");
		scanf("%c", &check);
	}
    printf("\nLinked List:\t");
    printNodes(head);
    printf("\n");

    node top = NULL;
    int choice=1;
    while(choice==1||choice==2){
        printf("\n\n1:\tPush\n2:\tPop\n\nChoice:\t");
        scanf("%d",&choice);
        if(choice==1){
            push(&top,&head);
            printf("\nLinked List:\t");
            printNodes(head);
            printf("\nStack:\t");
            printNodes(top);
        }
        else if(choice==2){
            pop(&top,&head);
            printf("\nLinked List:\t");
            printNodes(head);
            printf("\nStack:\t");
            printNodes(top);
        }
    }
}
//!SECTION Stack aur LL ka kalyanam