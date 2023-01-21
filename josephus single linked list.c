#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;

    struct Node* last = *head_ref;
    if (*head_ref != NULL) {
        while (last->next != *head_ref)
            last = last->next;
        last->next = new_node;
    } else {
        new_node->next = new_node;
    }
    *head_ref = new_node;
}

void josephus_problem(struct Node* head, int m) {
    struct Node* current = head;
    while (current->next != current) {
        for (int i = 0; i < m-1; i++) {
            current = current->next;
        }

        struct Node* next = current->next;
        printf("Killed: %d\n", next->data);

        current->next = next->next;
        free(next);
    }
    printf("Survivor: %d\n", current->data);
}

int main() {
    struct Node* head = NULL;
    int n = 6, m = 3;
    for (int i = 1; i <= n; i++) {
        push(&head, i);
    }
    josephus_problem(head, m);
    return 0;
}

