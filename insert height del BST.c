#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node* insert(struct node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    } else {
        if (data <= node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct node* node) {
    if (node == NULL) {
        return 0;
    } else {
        return 1 + max(height(node->left), height(node->right));
    }
}

struct node* findMinNode(struct node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

struct node* deleteNode(struct node* root, int data) {
    if (root == NULL) {
        return root;
    } else if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        } else if (root->left == NULL) {
            struct node* temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            struct node* temp = root;
            root = root->left;
            free(temp);
        } else {
            struct node* temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void printMenu() {
    printf("Binary Search Tree Operations\n");
    printf("1. Insert a node\n");
    printf("2. Display the height of the tree\n");
    printf("3. Delete a node from the tree\n");
    printf("4. Exit\n");
}

int main() {
    struct node* root = NULL;
    int choice, data;
    printMenu();
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data of the node to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("The height of the tree is: %d\n", height(root));
                break;
            case 3:
                printf("Enter the data of the node to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
                case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
                        }
                }
return 0;
}

