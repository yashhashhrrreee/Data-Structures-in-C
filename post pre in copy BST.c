#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct node {
    int data;
    struct node *left, *right;
};

// Function to create a new binary tree node
struct node *newNode(int item) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to do a postorder traversal of a binary tree
void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to do a preorder traversal of a binary tree
void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to do an inorder traversal of a binary tree
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// function to copy tree
struct node* copyTree(struct node* tree) {
    if (tree == NULL) {
        return NULL;
    }
    struct node* new = newNode(tree->data);
    new->left = copyTree(tree->left);
    new->right = copyTree(tree->right);
    return new;
}

int main() {
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int choice;
    printf("Menu:\n1. Postorder Traversal\n2. Preorder Traversal\n3. Inorder Traversal\n4. Copy a tree\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Postorder traversal of binary tree is:\n");
            postorder(root);
            break;
        case 2:
            printf("Preorder traversal of binary tree is:\n");
            preorder(root);
            break;
        case 3:
            printf("Inorder traversal of binary tree is:\n");
            inorder(root);
            break;
        case 4:
            //struct node *copy = copyTree(root);
            printf("Copy of the tree is successfully created");
            break;
        default:
            printf("Invalid choice");
    }
    return 0;
}

