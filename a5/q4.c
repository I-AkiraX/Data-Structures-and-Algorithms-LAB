#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *prev,*next;
}*head, *last;
void createList(int n) {
    int i, data;
    struct node *newNode;
    if(n >= 1) {
        head = (struct node *)malloc(sizeof(struct node));
        if(head != NULL) {
            printf("Node 1: ");
            scanf("%d", &data);
            head->data = data;
            head->prev = NULL;
            head->next = NULL;
            last = head;
            for(i=2; i<=n; i++) {
                newNode = (struct node *)malloc(sizeof(struct node));
                if(newNode != NULL) {
                    printf("Node %d: ", i);
                    scanf("%d", &data);
                    newNode->data = data;
                    newNode->prev = last;
                    newNode->next = NULL;
                    last->next = newNode;
                    last = newNode;
                }
                else {
                    printf("Unable to allocate memory.");
                    break;
                }
            }
            printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
        }
        else
            printf("Unable to allocate memory");
    }
}
void displayListFromFirst() {
    struct node * temp;
    int n = 1;
    if(head == NULL)
        printf("List is empty.");
    else {
        temp = head;
        printf("\n\nDATA IN THE LIST:\n");
        while(temp != NULL) {
            printf("Node %d = %d\n", n, temp->data);
            n++;
            temp = temp->next;
        }
    }
}
void displayListFromEnd() {
    struct node * temp;
    int n = 0;
    if(last == NULL)
        printf("List is empty.");
    else {
        temp = last;
        printf("\n\nDATA IN THE LIST:\n");
        while(temp != NULL) {
            printf("Node %d = %d\n", n, temp->data);
            n++;
            temp = temp->prev; 
        }
    }
}
void insertAtN(int data, int position) {
    int i;
    struct node * newNode, *temp;
    if(head == NULL) {
        printf("Error, List is empty!\n");
    }
    else {
        temp = head;
        i=1;
        while(i<position-1 && temp!=NULL) {
            temp = temp->next;
            i++;
        }
        if(position == 1) {
            insertAtBeginning(data);
        }
        else if(temp == last) {
            insertAtEnd(data);
        }
        else if(temp!=NULL) {
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = data;
            newNode->next = temp->next;
            newNode->prev = temp;
            if(temp->next != NULL) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            printf("NODE INSERTED SUCCESSFULLY\n", position);
        }
        else
            printf("Error, Invalid position\n");
    }
}
void deleteFromN(int position) {
    struct node *current;
    int i;
    current = head;
    for(i=1; i<position && current!=NULL; i++)
        current = current->next;
    if(position == 1)
        deleteFromBeginning();
    else if(current == last)
        deleteFromEnd();
    else if(current != NULL) {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
        printf("SUCCESSFULLY DELETED NODE\n", position);
    }
    else
        printf("Invalid position!\n");
}
int main() {
    int n, choice;
    float data;
    head = NULL;
    last = NULL;
    begin:
    printf("\nPress--\n1: To create a list.\n2: To display list from First\n3: To display list from End\n4: Insertion at specific position\n5: Deletion at specific position\n6: To exit\nYour choice:  ");
    scanf("%d", &choice);
    switch (choice){
    case 1:
        printf("Enter the number of nodes you want to create: "); 
        scanf("%d", &n);
        createList(n);
        goto begin;
        break;
    case 2:
        displayListFromFirst();
        goto begin;
        break;
    case 3:
        displayListFromEnd();
        goto begin;
        break;
    case 4:
        printf("Enter the position where you want to insert new node: ");
        scanf("%d", &n);
        printf("Enter the data: ", n);
        scanf("%d", &data);
        insertAtN(data, n);
        goto begin;
        break;
    case 5:
        printf("Enter the node position which you want to delete: ");
        scanf("%d", &n);
        deleteFromN(n);
        goto begin;
        break;
    case 6:
        exit(0);
    default:
        printf("Invalid choice!");
        break;
    }
}