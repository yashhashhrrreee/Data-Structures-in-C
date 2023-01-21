#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorderTraversal(struct node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void displayMirror(struct node* root) {
    if (root == NULL) return;
    struct node* temp;
    displayMirror(root->left);
    displayMirror(root->right);
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int height(struct node* root) {
    if (root == NULL) return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    if (lheight > rheight) return lheight + 1;
    else return rheight + 1;
}

int main() {
    int choice, data;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Preorder Traversal\n");
        printf("3. Display Mirror Image\n");
        printf("4. Display Height\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                if (root == NULL) {
                    root = createNode(data);
                } else {
                    struct node* temp = root;
                    while (1) {
                        if (data <= temp->data) {
                            if (temp->left == NULL) {
                                temp->left = createNode(data);
                                break;
                            } else {
                                temp = temp->left;
                            }
                        } else {
                            if (temp->right == NULL) {
                                temp->right = createNode(data);
                                break;
                            } else {
                                temp = temp->right;
                            }
                        }
                    }
                }
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                break;
            case 3:
                displayMirror(root);
                printf("Mirror Image Displayed");
                break;
            case 4:
                printf("Height of Tree: %d", height(root));
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
               break;
            }
    }
    return 0;
}


