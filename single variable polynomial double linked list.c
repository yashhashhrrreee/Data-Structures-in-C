#include <stdio.h>
#include <stdlib.h>

struct node {
    int coefficient;
    int exponent;
    struct node *prev;
    struct node *next;
} *start1 = NULL, *start2 = NULL, *start3 = NULL;

// Function to create a new node
struct node *createNode(int coef, int exp) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->coefficient = coef;
    newNode->exponent = exp;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to add new nodes to the polynomial
void addNode(int coef, int exp, struct node **start) {
    struct node *newNode = createNode(coef, exp);
    struct node *ptr = *start;

    if (*start == NULL) {
        *start = newNode;
        return;
    }

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = newNode;
    newNode->prev = ptr;
}

// Function to display the polynomial
void display(struct node *start) {
    struct node *ptr = start;

    while (ptr != NULL) {
        if (ptr->coefficient > 0) {
            printf(" +%dx^%d", ptr->coefficient, ptr->exponent);
        } else {
            printf(" %dx^%d", ptr->coefficient, ptr->exponent);
        }
        ptr = ptr->next;
    }
    printf("\n");
}

// Function to add two polynomials
void addPolynomials(struct node *start1, struct node *start2) {
    struct node *ptr1 = start1, *ptr2 = start2;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->exponent > ptr2->exponent) {
            addNode(ptr1->coefficient, ptr1->exponent, &start3);
            ptr1 = ptr1->next;
        } else if (ptr1->exponent < ptr2->exponent) {
            addNode(ptr2->coefficient, ptr2->exponent, &start3);
            ptr2 = ptr2->next;
        } else {
            int coef = ptr1->coefficient + ptr2->coefficient;
            if (coef != 0) {
                addNode(coef, ptr1->exponent, &start3);
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL) {
        addNode(ptr1->coefficient, ptr1->exponent, &start3);
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL) {
        addNode(ptr2->coefficient, ptr2->exponent, &start3);
        ptr2 = ptr2->next;
    }
}

// Function to multiply two polynomials
// Function to multiply two polynomials
void multiplyPolynomials(struct node *start1, struct node *start2) {
    struct node *ptr1, *ptr2;

    for (ptr1 = start1; ptr1 != NULL; ptr1 = ptr1->next) {
        for (ptr2 = start2; ptr2 != NULL; ptr2 = ptr2->next) {
            int coef = ptr1->coefficient * ptr2->coefficient;
            int exp = ptr1->exponent + ptr2->exponent;
            addNode(coef, exp, &start3);
        }
    }
}
int main() {
    //Accept a polynomial
    int coef, exp;
    while (1) {
        printf("Enter coefficient and exponent of term (0 0 to exit): ");
        scanf("%d %d", &coef, &exp);
        if (coef == 0 && exp == 0) break;
        addNode(coef, exp, &start1);
    }

    printf("Polynomial 1: ");
    display(start1);

    //Accept another polynomial
    while (1) {
        printf("Enter coefficient and exponent of term (0 0 to exit): ");
        scanf("%d %d", &coef, &exp);
        if (coef == 0 && exp == 0)
            break;
        addNode(coef, exp, &start2);
    }

    printf("Polynomial 2: ");
    display(start2);

    //Add the polynomials
    addPolynomials(start1, start2);
    printf("Sum: ");
    display(start3);

    //Multiply the polynomials
    start3 = NULL;
    multiplyPolynomials(start1, start2);
    printf("Product: ");
    display(start3);
    //Freeing allocated memory
    //and any other necessary cleanup code here
    return 0;
}
