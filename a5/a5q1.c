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
        printf(" Input data for node 1 : ");
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
void insertNode(int data){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Unable to allocate memory.");
    }
    else{
        newNode->num = data;
        newNode->next = stnode;
        stnode = newNode;
        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}
int main(){
    int n,data,c;
    here:
    printf("\n\nPress:\n1- Create a list.\n2- Display the list.\n3- Insert data at the beginning of the list.\n4- Exit.\nYour choice:  ");
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
        printf("\nEnter the data you want to add : ");
        scanf("%d",&data);
        insertNode(data);
        goto here;
    }
    else if (c==4) {
        exit(0);
    }
    else {
        printf("\n\nWrong choice! Please enter again -- \n");
        goto here;
    }
    return 0;
}