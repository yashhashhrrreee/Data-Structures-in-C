#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

// Copy a tree
struct Node* copyTree(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }

    struct Node* newRoot = createNode(root->data);
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);
    return newRoot;
}

// Equality of two trees
int isEqual(struct Node* root1, struct Node* root2) {
    if (root1 == NULL && root2 == NULL) {
        return 1;
    } else if (root1 != NULL && root2 != NULL) {
        return (root1->data == root2->data) &&
               isEqual(root1->left, root2->left) &&
               isEqual(root1->right, root2->right);
    } else {
        return 0;
    }
}

// Delete a node from a tree
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        } else {
            struct Node* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    struct Node* root = NULL;

    int choice, data;
    while (1) {
        printf("\nMenu:\n");
                printf("1. Insert a node into the tree\n");
        printf("2. Copy the tree\n");
        printf("3. Check if two trees are equal\n");
        printf("4. Delete a node from the tree\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2: {
                struct Node* copy = copyTree(root);
                printf("The copied tree is: ");
                //print the copied tree here if you want
                break;
            }
            case 3: {
                struct Node* root2 = NULL;
                //create the second tree here
                if (isEqual(root, root2)) {
                    printf("The two trees are equal\n");
                } else {
                    printf("The two trees are not equal\n");
                }
                break;
            }
            case 4:
                printf("Enter the data of the node to be deleted: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}


