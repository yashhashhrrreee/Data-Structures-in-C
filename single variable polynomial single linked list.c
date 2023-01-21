#include <stdio.h>
#include <stdlib.h>

// Structure for a single node of the linked list
struct node {
    int coefficient;
    int exponent;
    struct node *next;
};

// Function to create a new node
struct node* create_node(int coefficient, int exponent) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->coefficient = coefficient;
    new_node->exponent = exponent;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the end of the list
void insert_node(struct node** head, int coefficient, int exponent) {
    struct node* new_node = create_node(coefficient, exponent);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node* ptr = *head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
}

// Function to accept a polynomial
void accept_polynomial(struct node** head) {
    int coefficient, exponent;
    printf("Enter the coefficient and exponent (enter -1 -1 to end): ");
    scanf("%d %d", &coefficient, &exponent);
    while (coefficient != -1 && exponent != -1) {
        insert_node(head, coefficient, exponent);
        printf("Enter the coefficient and exponent (enter -1 -1 to end): ");
        scanf("%d %d", &coefficient, &exponent);
    }
}

// Function to display a polynomial
void display_polynomial(struct node* head) {
    struct node* ptr = head;
    while (ptr != NULL) {
        if (ptr->exponent == 0) {
            printf("%d", ptr->coefficient);
        } else {
            printf("%d*x^%d", ptr->coefficient, ptr->exponent);
        }
        ptr = ptr->next;
        if (ptr != NULL) {
            printf(" + ");
        }
    }
}

// Function to add two polynomials
struct node* add_polynomials(struct node* head1, struct node* head2) {
    struct node* head3 = NULL;
    struct node* ptr1 = head1, *ptr2 = head2;
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->exponent == ptr2->exponent) {
            int coefficient = ptr1->coefficient + ptr2->coefficient;
            if (coefficient != 0) {
                insert_node(&head3, coefficient, ptr1->exponent);
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } else if (ptr1->exponent > ptr2->exponent) {
            insert_node(&head3, ptr1->coefficient, ptr1->exponent);
            ptr1 =            ptr1->next;
        } else {
            insert_node(&head3, ptr2->coefficient, ptr2->exponent);
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL) {
        insert_node(&head3, ptr1->coefficient, ptr1->exponent);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL) {
        insert_node(&head3, ptr2->coefficient, ptr2->exponent);
        ptr2 = ptr2->next;
    }
    return head3;
}

// Function to multiply two polynomials
struct node* multiply_polynomials(struct node* head1, struct node* head2) {
    struct node* head4 = NULL;
    struct node* ptr1 = head1;
    while (ptr1 != NULL) {
        struct node* ptr2 = head2;
        while (ptr2 != NULL) {
            int coefficient = ptr1->coefficient * ptr2->coefficient;
            int exponent = ptr1->exponent + ptr2->exponent;
            insert_node(&head4, coefficient, exponent);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return head4;
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;

    printf("Enter the first polynomial:\n");
    accept_polynomial(&head1);

    printf("Enter the second polynomial:\n");
    accept_polynomial(&head2);

    printf("\nFirst polynomial: ");
    display_polynomial(head1);

    printf("\nSecond polynomial: ");
    display_polynomial(head2);

    struct node* head3 = add_polynomials(head1, head2);
    printf("\nSum: ");
    display_polynomial(head3);

    struct node* head4 = multiply_polynomials(head1, head2);
    printf("\nProduct: ");
    display_polynomial(head4);

    return 0;
}

