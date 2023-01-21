#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

struct node *newNode(int item) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

void inorderTraversal(struct node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

void mirror(struct node* node) {
    if (node == NULL) return;

    struct node* temp;

    mirror(node->left);
    mirror(node->right);

    temp = node->left;
    node->left = node->right;
    node->right = temp;
}

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        //struct node* temp = minValueNode(root->right);

        //root->key = temp->key;
        //root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main() {
    struct node *root = NULL;
    int choice, x;

    while (1) {
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Display Mirror Image of Tree\n");
        printf("4. Delete a node\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to be inserted: ");
                scanf("%d",&x);
                root = insert(root, x);
                break;
            case 2:
                printf("Inorder traversal of the BST: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                mirror(root);
                printf("Mirror image of the tree is created.\n");
                break;
            case 4:
                printf("Enter the key of the node to be deleted: ");
                scanf("%d", &x);
                root = deleteNode(root, x);
                break;
            case 5:
                exit(1);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

