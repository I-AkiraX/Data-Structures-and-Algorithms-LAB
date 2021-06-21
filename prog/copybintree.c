// copy binary tree

#include <stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node* getNewNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct node* generateBTree(){
    struct node* root =  getNewNode(1);
    root->left = getNewNode(9);
    root->right = getNewNode(12);
    root->left->left = getNewNode(4);
    root->left->right = getNewNode(50);
    root->right->right = getNewNode(-7);
    root->left->left->left = getNewNode(18);
    root->left->left->right = getNewNode(9);
    return root;
}
struct node* cloneBinaryTree(struct node *root){
    if(root == NULL)
        return NULL;
    struct node* newNode = getNewNode(root->data);
    newNode->left = cloneBinaryTree(root->left);
    newNode->right = cloneBinaryTree(root->right);
    return newNode;
}
void inOrderTraversal(struct node *nodeptr){
    if(nodeptr != NULL){
        inOrderTraversal(nodeptr->left);
        printf("%d ", nodeptr->data);
        inOrderTraversal(nodeptr->right);
    }
}
int main() {
    struct node *clone, *root = generateBTree();
    printf("Original Tree\n");
    inOrderTraversal(root);
    clone = cloneBinaryTree(root);
    printf("\nClone Tree\n");
    inOrderTraversal(clone);
}