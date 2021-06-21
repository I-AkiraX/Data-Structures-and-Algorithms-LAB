//finding inorder successor

#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node* left,* right,* parent;
};

//returns the minimum element in the right tree
struct node* minValue(struct node* current){
	if(current->right==NULL){
		return NULL;
	}
	else{
		struct node* n = current->right;
		while(n->left!=NULL){
			n = n->left;
		}
		return n;
	}
}
//returns the node for which inorder successor is desired
struct node* getNode(struct node* root, int key){
    struct node* temp = NULL;
	if(root!=NULL){
    	temp = getNode(root->left,key);
    	if(root->data==key){
			return root;
		}
		if(temp!=NULL){
			return temp;
		}
		temp = getNode(root->right,key);
	}
	return temp;
}
// returns the inorder successor (or NULL)
struct node* inOrderSuccessor(struct node* root,struct node* n){
    struct node* newRoot = getNode(root,n->data);
	if(newRoot==NULL){
		printf("\n\nNode does not exist!");
	}
	struct node* succ = minValue(newRoot);
	return succ;
}


//create new node
struct node* newNode(int data){ 
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	return (node);
}
//inserts node in tree
struct node* insert(struct node* node,int data){
	if (node == NULL)
		return (newNode(data));
	else {
		struct node* temp;
		if (data <= node->data) {
			temp = insert(node->left, data);
			node->left = temp;
			temp->parent = node;
		}
		else {
			temp = insert(node->right, data);
			node->right = temp;
			temp->parent = node;
		}
		return node;
	}
}
//prints in inorder
void inOrderTraversal(struct node* nodeptr){
    if(nodeptr != NULL){
        inOrderTraversal(nodeptr->left);
        printf("%d ", nodeptr->data);
        inOrderTraversal(nodeptr->right);
    }
}
//Driver code
int main(){ 
	struct node *root = NULL, *temp = NULL, *succ;
    char ch='y';
    int x;
    while (ch=='y'){
        printf("Enter the value:  ");
        scanf("%d",&x);
        root = insert(root,x);
        scanf("%*c");
        printf("Enter 'y' to enter more:  ");
        scanf("%c",&ch);
    }
    printf("Enter the value whose successor you want to find:  ");
    scanf("%d",&x);
    temp = insert(temp,x);
    printf("\nTree--\n");
    inOrderTraversal(root);
    printf("\ntemp--\n");
    inOrderTraversal(temp);
	succ = inOrderSuccessor(root, temp);
	if (succ != NULL)
		printf("\n\nInorder Successor of %d is %d ",temp->data, succ->data);
	else
		printf("\n\nInorder Successor doesn't exit");
}