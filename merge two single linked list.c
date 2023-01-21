#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* mergeSortedLists(struct node* head1, struct node* head2) {
    struct node dummy;
    struct node* tail = &dummy;
    dummy.next = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    tail->next = (head1 != NULL) ? head1 : head2;
    return dummy.next;
}

// Helper function to create a new node
struct node* newNode(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Helper function to add new node to the list
void push(struct node** head_ref, int data) {
    struct node* new_node = newNode(data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    struct node* list1 = NULL;
    struct node* list2 = NULL;

    // Create first sorted linked list
    push(&list1, 7);
    push(&list1, 5);
    push(&list1, 3);
    push(&list1, 2);

    // Create second sorted linked list
    push(&list2, 6);
    push(&list2, 4);
    push(&list2, 1);

    struct node* mergedList = mergeSortedLists(list1, list2);

    // print out the merged list
    struct node* current = mergedList;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}
