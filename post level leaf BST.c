#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void levelOrder(struct Node* root) {
    int h = height(root);
    for (int i=1; i<=h; i++)
        printGivenLevel(root, i);
}

void printGivenLevel(struct Node* root, int level) {
    if (root == NULL) return;
    if (level == 1) printf("%d ", root->data);
    else if (level > 1) {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

int height(struct Node* root) {
    if (root == NULL) return 0;
    int left = height(root->left);
    int right = height(root->right);
    if (left > right) return (left+1);
    else return (right+1);
}

void leafNodes(struct Node* root) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL)
            printf("%d ", root->data);
        leafNodes(root->left);
        leafNodes(root->right);
    }
}

int main() {
    int choice, data;
    struct Node* root = NULL;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Postorder Traversal\n");
        printf("3. Display Tree Levelwise\n");
        printf("4. Display Leaf Nodes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter the data: ");
                    scanf("%d", &data);
                    root = insert(root, data);
                    break;
            case 2: printf("Postorder Traversal: ");
                    postorder(root);
                    break;
            case 3: printf("Tree Levelwise: ");
                    levelOrder(root);
                    break;
            case 4: printf("Leaf Nodes: ");
                    leafNodes(root);
                    break;
            case 5: exit(0);
break;
default: printf("Invalid choice. Try again.\n");
}
}
return 0;
}

