#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

struct Polynomial {
    struct Term* first;
};

// Function to create a new term in a polynomial
struct Term* createTerm(int coefficient, int exponent) {
    struct Term* newTerm = (struct Term*) malloc(sizeof(struct Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to create a new polynomial
struct Polynomial* createPolynomial() {
    struct Polynomial* newPoly = (struct Polynomial*) malloc(sizeof(struct Polynomial));
    newPoly->first = NULL;
    return newPoly;
}

// Function to add a term to a polynomial
void addTerm(struct Polynomial* poly, int coefficient, int exponent) {
    struct Term* newTerm = createTerm(coefficient, exponent);

    if (poly->first == NULL) {
        poly->first = newTerm;
    } else {
        struct Term* current = poly->first;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to display a polynomial
void display(struct Polynomial* poly) {
    struct Term* current = poly->first;
    while (current != NULL) {
        printf("(%d)x^(%d) + ", current->coefficient, current->exponent);
        current = current->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct Polynomial* add(struct Polynomial* poly1, struct Polynomial* poly2) {
    struct Polynomial* result = createPolynomial();

    struct Term* current1 = poly1->first;
    struct Term* current2 = poly2->first;

    while (current1 != NULL && current2 != NULL) {
        if (current1->exponent > current2->exponent) {
            addTerm(result, current1->coefficient, current1->exponent);
            current1 = current1->next;
        } else if (current1->exponent < current2->exponent) {
            addTerm(result, current2->coefficient, current2->exponent);
            current2 = current2->next;
        } else {
            int coefficient = current1->coefficient + current2->coefficient;
            if (coefficient != 0) {
                addTerm(result, coefficient, current1->exponent);
            }
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    while (current1 != NULL) {
        addTerm(result, current1->coefficient, current1->exponent);
        current1 = current1->next;
    }

        while (current2 != NULL) {
        addTerm(result, current2->coefficient, current2->exponent);
        current2 = current2->next;
    }

    return result;
}

// Function to multiply two polynomials
struct Polynomial* multiply(struct Polynomial* poly1, struct Polynomial* poly2) {
    struct Polynomial* result = createPolynomial();

    struct Term* current1 = poly1->first;
    while (current1 != NULL) {
        struct Term* current2 = poly2->first;
        while (current2 != NULL) {
            int coefficient = current1->coefficient * current2->coefficient;
            int exponent = current1->exponent + current2->exponent;
            addTerm(result, coefficient, exponent);
            current2 = current2->next;
        }
        current1 = current1->next;
    }

    return result;
}

int main() {
    struct Polynomial* poly1 = createPolynomial();
    struct Polynomial* poly2 = createPolynomial();

    // Accept and display polynomial 1
    printf("Enter the terms for polynomial 1:\n");
    int coefficient, exponent;
    char choice;
    do {
        printf("Enter coefficient: ");
        scanf("%d", &coefficient);
        printf("Enter exponent: ");
        scanf("%d", &exponent);
        addTerm(poly1, coefficient, exponent);
        printf("Do you want to add more terms to polynomial 1? (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');
    printf("Polynomial 1: ");
    display(poly1);

    // Accept and display polynomial 2
    printf("Enter the terms for polynomial 2:\n");
    do {
        printf("Enter coefficient: ");
        scanf("%d", &coefficient);
        printf("Enter exponent: ");
        scanf("%d", &exponent);
        addTerm(poly2, coefficient, exponent);
        printf("Do you want to add more terms to polynomial 2? (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');
    printf("Polynomial 2: ");
    display(poly2);

    // Perform addition and multiplication of polynomials
    struct Polynomial* sum = add(poly1, poly2);
    struct Polynomial* product = multiply(poly1, poly2);

    printf("Sum of polynomials: ");
    display(sum);
    printf("Product of polynomials: ");
    display(product);

    return 0;
}


