#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void postorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void levelOrder(struct Node* root) {
    int h = height(root);
    int i;
    for (i=1; i<=h; i++) {
        printGivenLevel(root, i);
    }
}

void printGivenLevel(struct Node* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (leftHeight > rightHeight) {
        return leftHeight+1;
    } else {
        return rightHeight+1;
    }
}

void leafNodes(struct Node* root) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
    }
    leafNodes(root->left);
    leafNodes(root->right);
}

int main() {
    struct Node* root = NULL;
    int data, choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Perform postorder traversal\n");
        printf("3. Display tree level-wise\n");
        printf("4. Display leaf nodes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
                switch (choice) {
            case 1:
                printf("Enter data for the node: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Postorder traversal: ");
                postorder(root);
                break;
            case 3:
                printf("Tree level-wise: ");
                levelOrder(root);
                break;
            case 4:
                printf("Leaf nodes: ");
                leafNodes(root);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}

