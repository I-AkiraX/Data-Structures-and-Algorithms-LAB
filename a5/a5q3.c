#include <stdio.h>
#include <stdlib.h>
struct node {
    int num;
    struct node *next;
}*stnode;
void createList(int n){
    struct node *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));
    if(stnode == NULL){
        printf(" Memory can not be allocated.");
    }
    else{
        printf("Node 1 : ");
        scanf("%d", &num);
        stnode->num = num;      
        stnode->next = NULL;
        tmp = stnode;
        for(i=2; i<=n; i++){
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL){
                printf(" Memory can not be allocated.");
                break;
            }
            else{
                printf("Node %d : ", i);
                scanf(" %d", &num);
                fnNode->num = num;
                fnNode->next = NULL;
                tmp->next = fnNode;
                tmp = tmp->next; 
            }
        }
    }
}
void displayList(){
    struct node *tmp;
    if(stnode == NULL){
        printf(" List is empty.");
    }
    else{
        tmp = stnode;
        while(tmp != NULL){
            printf("%d  ", tmp->num);
            tmp = tmp->next;
        }
    }
}
void deleteLastNode(){
    struct node *toDelete, *secondLastNode;
    if(stnode == NULL){
        printf("List is already empty.");
    }
    else{
        toDelete = stnode;
        secondLastNode = stnode;
        while(toDelete->next != NULL){
            secondLastNode = toDelete;
            toDelete = toDelete->next;
        }
        if(toDelete == stnode){
            stnode = NULL;
        }
        else{
            secondLastNode->next = NULL;
        }
        free(toDelete);
        printf("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
    }
}
void deleteNode(int position){
    int i;
    struct node *toDelete, *prevNode;
    if(stnode == NULL){
        printf("List is already empty.");
    }
    else{
        toDelete = stnode;
        prevNode = stnode;
        for(i=2; i<=position; i++){
            prevNode = toDelete;
            toDelete = toDelete->next;
            if(toDelete == NULL)
                break;
        }
        if(toDelete != NULL){
            if(toDelete == stnode)
                stnode = stnode->next;
            prevNode->next = toDelete->next;
            toDelete->next = NULL;
            free(toDelete);
            printf("SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST\n");
        }
        else{
            printf("Invalid position unable to delete.");
        }
    }
}
int main(){
    int n,pos,c;
    here:
    printf("\n\nPress:\n1- Create a list.\n2- Display the list.\n3- Delete the data at the end.\n4- Delete data at the specified location.\n5- Exit.\nYour choice:  ");
    scanf("%d",&c);
    if (c==1) {
        printf("Input the number of nodes : ");
        scanf("%d", &n);
        createList(n);
        goto here;
    }
    else if (c==2) {
        printf("\nData entered in the list --\n");
        displayList();
        goto here;
    }
    else if (c==3) {
        deleteLastNode();
        goto here;
    }
    else if(c==4){
        printf("Enter the position at which you want to add:  ");
        scanf("%d",&pos);
        deleteNode(pos);
        goto here;
    }
    else if (c==5) {
        exit(0);
    }
    else {
        printf("\n\nWrong choice! Please enter again -- \n");
        goto here;
    }
    return 0;
}