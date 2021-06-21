//SECTION BST Full Program
#include<stdio.h>
#include<stdlib.h>

struct Node{
	int key;
	struct Node *leftChild;
	struct Node *rightChild;
};
typedef struct Node* node;
// A utility function to create a new BST Node
//ANCHOR create and return a node
node createNode()
{
     node temp;
     temp = (node)malloc(sizeof(struct Node));
     temp->leftChild = NULL;
     temp->rightChild = NULL;
     return temp;
}

//ANCHOR create tree using reccursion
node createTree(node root, int num)
{
     node temp = createNode();
     temp->key = num;
	/* If the tree is empty, return a new Node */
	if (root == NULL){
          return temp;
     }

	/* Otherwise, recur down the tree */
	if (num < root->key)
		root->leftChild = createTree(root->leftChild, num);
	else
		root->rightChild = createTree(root->rightChild, num);

	/* return the (unchanged) Node pointer */
	return root;
}
//!SECTION create Tree Full Code


//SECTION TREE traveral functions

// ANCHOR postOrder function (traversal and printing of tree)
void printPostOrder(node root)
{
	if (root == NULL)
		return;
	printPostOrder(root->leftChild);
	printPostOrder(root->rightChild);
	printf("%d ", root->key);
}
//print postOrder (traversal and printing of tree)

// ANCHOR inOrder function (traversal and printing of tree)
void printInOrder(node root)
{
	if (root == NULL)
		return;
	printInOrder(root->leftChild);
	printf("%d ", root->key);
	printInOrder(root->rightChild);
}
//print inOrder (traversal and printing of tree)

// ANCHOR preOrder function (traversal and printing of tree)
void printPreOrder(node root)
{
	if (root == NULL)
		return;
	printf("%d ", root->key);
	printPreOrder(root->leftChild);
	printPreOrder(root->rightChild);
}
//print preOrder (traversal and printing of tree)
//!SECTION


//SECTION DELETING A NODE
/* Given a non-empty binary search 
tree, return the Node
with minimum key value found in
that tree. Note that the
entire tree does not need to be searched. */
node minValueNode(node root)
{
	node current = root;

	/* loop down to find the leftChildmost leaf */
	while (current && current->leftChild != NULL)
		current = current->leftChild;

	return current;
}
//ANCHOR delete a node
/* Given a binary search tree 
and a key, this function
deletes the key and 
returns the new root */
node deleteNode(node root, int key)
{
	// base case
	if (root == NULL)
		return root;

	// If the key to be deleted is smaller than the root's key, then it lies in leftChild subtree
	if (key < root->key)
		root->leftChild = deleteNode(root->leftChild, key);

	// If the key to be deleted is greater than the root's key, then it lies in rightChild subtree
	else if (key > root->key)
		root->rightChild = deleteNode(root->rightChild, key);

	// if key is same as root's key, then This is the Node to be deleted
	else
	{
		// Node with only one child or no child
		if (root->leftChild == NULL)
		{
			node temp = root->rightChild;
			free(root);
			return temp;
		}
		else if (root->rightChild == NULL)
		{
			node temp = root->leftChild;
			free(root);
			return temp;
		}

		// Node with two children: Get the inorder successor(smallest in the rightChild subtree)
		node temp = minValueNode(root->rightChild);

		// Copy the inorder successor's content to this Node
		root->key = temp->key;

		// Delete the inorder successor
		root->rightChild = deleteNode(root->rightChild, temp->key);
	}
	return root;
}
//!SECTION DELETING A NODE

//ANCHOR MAIN FUNCTION
void main()
{
	node root = NULL;
    int check = -100;
	while (check == -100)
	{
		int key;
		printf("Enter a number to store in BST:\t");
		scanf("%d", &key);
		root = insert(root, key);
		printf("Enter '-100' to continue entering.");
		scanf("%d", &check);
	}

	printf("Printing inOrder:\t");
	printInOrder(root); //print inOrder
	printf("Printing in preOrder:\t");
	printPreOrder(root); //print preOrder
	printf("Printing in postOrder:\t");
	printPostOrder(root); //print postOrder
	root = deleteNode(root, 5);
	printf("Printing inOrder:\t");
	printInOrder(root); //print inOrder
	/*
	printf("\nDelete 20\n");
	root = deleteNode(root, 20);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);

	printf("\nDelete 30\n");
	root = deleteNode(root, 30);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);

	printf("\nDelete 50\n");
	root = deleteNode(root, 50);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);*/
}
//!SECTION BST Full Program