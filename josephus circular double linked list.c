#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = new_node;
    new_node->next = new_node;
    return new_node;
}

void insert_node(struct node *head, int data) {
    struct node *new_node = create_node(data);
    new_node->prev = head->prev;
    new_node->next = head;
    head->prev->next = new_node;
    head->prev = new_node;
}

void delete_node(struct node *head, struct node *del_node) {
    if (head == del_node) {
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
    }
    else {
        del_node->prev->next = del_node->next;
        del_node->next->prev = del_node->prev;
    }
    free(del_node);
}

int josephus(int n, int k) {
    struct node *head = create_node(1);
    for (int i = 2; i <= n; i++) {
        insert_node(head, i);
    }

    struct node *current = head;
    while (current->next != current) {
        for (int i = 1; i < k; i++) {
            current = current->next;
        }
        struct node *temp = current;
        current = current->next;
        delete_node(head, temp);
    }

    return current->data;
}

int main() {
    int n, k;
    printf("Enter the value of n and k: ");
    scanf("%d%d", &n, &k);
    printf("The winning position is: %d\n", josephus(n, k));
    return 0;
}

