#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *createTree(struct node *root, int data) {
    if(root == NULL) {
        return createNode(data);
    }
    if(data < root->data) {
        root->left = createTree(root->left, data);
    } else {
        root->right = createTree(root->right, data);
    }
    return root;
}

void postorderTraversal(struct node *root) {
    if(root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

void preorderTraversal(struct node *root) {
    if(root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(struct node *root) {
    if(root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

struct node *copyTree(struct node *root) {
    if(root == NULL) {
        return NULL;
    }
    struct node *newNode = createNode(root->data);
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);
    return newNode;
}

int main() {
    struct node *root = NULL;
    int choice, data;
    while(1) {
        printf("\nBinary Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Postorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Inorder Traversal\n");
        printf("5. Copy Tree\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                root = createTree(root, data);
                break;
            case 2:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                                break;
            case 5:
                printf("Copying tree...\n");
                struct node *copy = copyTree(root);
                printf("Copy of tree: ");
                inorderTraversal(copy);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}


