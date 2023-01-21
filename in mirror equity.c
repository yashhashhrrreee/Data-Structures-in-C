#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// inorder traversal of a binary tree
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// mirror image of a binary tree
struct node* mirror(struct node* root) {
    if (root == NULL)
        return NULL;
    else {
        struct node* left = mirror(root->left);
        struct node* right = mirror(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
}

// check if two trees are equal
int isEqual(struct node* a, struct node* b) {
    if (a == NULL && b == NULL)
        return 1;
    if (a != NULL && b != NULL) {
        return
            (
                a->data == b->data &&
                isEqual(a->left, b->left) &&
                isEqual(a->right, b->right)
                );
    }
    return 0;
}

int main() {
    int choice;
    struct node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    struct node *root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inorder Traversal\n");
        printf("2. Display mirror image of a tree by creating new tree\n");
        printf("3. Equality of two trees\n");
        printf("4. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Inorder Traversal of tree 1:\n");
            inorder(root1);
            break;
        case 2:
            printf("Mirror image of tree 1:\n");
            root1 = mirror(root1);
            inorder(root1);
            break;
        case 3:
            if (isEqual(root1, root2))
                printf("Both trees are identical.\n");
            else
                printf("Trees are not identical.\n");
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
            }
    return 0;
}


