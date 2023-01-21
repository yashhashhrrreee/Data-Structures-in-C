#include <stdio.h>
#include <stdlib.h>

struct Node {
    double data;
    struct Node* prev;
    struct Node* next;
};

// Create a new node with given data
struct Node* newNode(double data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->prev = temp->next = NULL;
    return temp;
}

// Insert a new node with given data into a sorted double linked list
struct Node* insertSorted(struct Node* head, double data) {
    // Create the new node
    struct Node* new = newNode(data);

    // Special case: the list is empty or the new data is smaller than the head
    if (!head || head->data > data) {
        new->next = head;
        if (head)
            head->prev = new;
        return new;
    }

    // Locate the node before the point of insertion
    struct Node* current = head;
    while (current->next && current->next->data < data) {
        current = current->next;
    }

    // Insert the new node
    new->next = current->next;
    new->prev = current;
    if (current->next)
        current->next->prev = new;
    current->next = new;
    return head;
}

// Merge two sorted double linked lists and return the head of the merged list
struct Node* merge(struct Node* head1, struct Node* head2) {
    struct Node dummy;
    struct Node* tail = &dummy;

    while (head1 && head2) {
        if (head1->data < head2->data) {
            tail->next = head1;
            head1->prev = tail;
            head1 = head1->next;
        }
        else {
            tail->next = head2;
            head2->prev = tail;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    if (head1) {
        tail->next = head1;
        head1->prev = tail;
    }
    else {
        tail->next = head2;
        head2->prev = tail;
    }

    return dummy.next;
}

    int main() {
        // Create the first list
        struct Node* head1 = NULL;
        head1 = insertSorted(head1, 1.2);
        head1 = insertSorted(head1, 2.3);
        head1 = insertSorted(head1, 3.4);

        // Create the second list
        struct Node* head2 = NULL;
        head2 = insertSorted(head2, 2.5);
        head2 = insertSorted(head2, 3.6);
        head2 = insertSorted(head2, 4.7);

        // Merge the two lists
        struct Node* head = merge(head1, head2);

        // Print the merged list
        struct Node* current = head;
        while (current) {
            printf("%.1f ", current->data);
            current = current->next;
        }

        return 0;
    }

