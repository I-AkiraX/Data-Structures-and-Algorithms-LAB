#include <stdio.h>
#include <stdlib.h>
struct node {
    int num;
    struct node *next;
}*stnode;
void createList(int n) {
    struct node *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));
    if(stnode == NULL) {
        printf("Memory can not be allocated.");
    }
    else {
        printf("Node 1: ");
        scanf("%d", &num);
        stnode->num = num;      
        stnode->next = NULL;
        tmp = stnode;
        for(i=2; i<=n; i++) {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL) {
                printf("Memory can not be allocated.");
                break;
            }
            else {
                printf("Node %d: ", i);
                scanf(" %d", &num);
                fnNode->num = num;
                fnNode->next = NULL;
                tmp->next = fnNode;
                tmp = tmp->next; 
            }
        }
    }
}
void displayList() {
    struct node *tmp;
    if(stnode == NULL) {
        printf("List is empty.");
    }
    else {
        tmp = stnode;
        while(tmp != NULL) {
            printf("%d  ", tmp->num);
            tmp = tmp->next;
        }
    }
}
void insertNode(int data) {
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL) {
        printf("Unable to allocate memory.");
    }
    else {
        newNode->num = data;
        newNode->next = stnode;
        stnode = newNode;
        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}
void insert(int data, int position) {
    int i;
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL) {
        printf("Unable to allocate memory.");
    }
    else {
        newNode->num = data;
        newNode->next = NULL;
        temp = stnode;
        for(i=2; i<=position-1; i++) {
            temp = temp->next;
            if(temp == NULL)
                break;
        }
        if(temp != NULL) {
            newNode->next = temp->next;
            temp->next = newNode;
            printf("DATA INSERTED SUCCESSFULLY\n");
        }
        else {
            printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
        }
    }
}
void insertAtEnd(int data) {
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL) {
        printf("Unable to allocate memory.");
    }
    else {
        newNode->num = data;
        newNode->next = NULL;
        temp = stnode;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}
void deleteBeg(){
    struct node *temp;
    temp = stnode;
    stnode = stnode->next;
    free(temp);
    printf("SUCCESSFULLY DELETED FIRST NODE OF LIST\n");
}
void deleteNode(int position) {
    int i;
    struct node *toDel, *prevNode;
    if(stnode == NULL) {
        printf("List is already empty.");
    }
    else {
        toDel = stnode;
        prevNode = stnode;
        for(i=2; i<=position; i++) {
            prevNode = toDel;
            toDel = toDel->next;
            if(toDel == NULL)
                break;
        }
        if(toDel != NULL) {
            if(toDel == stnode)
                stnode = stnode->next;
            prevNode->next = toDel->next;
            toDel->next = NULL;
            free(toDel);
            printf("SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST\n");
        }
        else {
            printf("Invalid position unable to delete.");
        }
    }
}
void deleteLast() {
    struct node *toDel, *secLast;
    if(stnode == NULL) {
        printf("List is already empty.");
    }
    else {
        toDel = stnode;
        secLast = stnode;
        while(toDel->next != NULL) {
            secLast = toDel;
            toDel = toDel->next;
        }
        if(toDel == stnode) {
            stnode = NULL;
        }
        else {
            secLast->next = NULL;
        }
        free(toDel);
        printf("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
    }
}
int main() {
    int n,data,pos,c;
    here:
    printf("\n\nPress:\n1- Create a list.\n2- Display list.\n3- Insert data at beginning of list.\n4- Insert data at specific position.\n5- Insert data at end.\n6- Delete the data at beginning.\n7- Delete data at the specified location.\n8- Delete the data at the end.\n9- Exit.\nYour choice:  ");
    scanf("%d",&c);
    if(c<1&&c>8) {
        printf("\n\nWrong choice! Please enter again -- \n");
        goto here;
    }
    if (c==1) {
        printf("Input the number of nodes:  ");
        scanf("%d", &n);
        createList(n);
        goto here;
    }
    else if (c==2) {
        printf("\nData entered in the list --\n");
        displayList();
        goto here;
    }
    else if(c==3) {
        printf("\nEnter the data you want to add : ");
        scanf("%d",&data);
        insertNode(data);
        goto here;
    }
    else if (c==4) {
        printf("\nEnter the position at which you want to add:  ");
        scanf("%d",&pos);
        printf("\nEnter the data you want to add:  ");
        scanf("%d",&data);
        insert(data,pos);
        goto here;
    }
    else if (c==5) {
        printf("\nEnter the data you want to add:  ");
        scanf("%d",&data);
        insertAtEnd(data);
        goto here;
    }
    else if(c==6){
        deleteBeg();
        goto here;
    }
    else if(c==7) {
        printf("\nEnter the position at which you want to delete:  ");
        scanf("%d",&pos);
        deleteNode(pos);
        goto here;
    }
    else if (c==8) {
        deleteLast();
        goto here;
    }
    else
        exit(0);
}