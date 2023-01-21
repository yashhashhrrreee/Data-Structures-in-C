#include <stdio.h>
#include <stdlib.h>

struct PolyNode {
    double coef;   // coefficient
    int expon;     // exponent
    struct PolyNode *next;
    struct PolyNode *prev;
};
typedef struct PolyNode *Polynomial;

// Function to create a new polynomial node
Polynomial NewNode(double coef, int expon) {
    Polynomial P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef = coef;
    P->expon = expon;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

// Function to insert a new node into a polynomial
void Attach(double coef, int expon, Polynomial *P) {
    Polynomial T = NewNode(coef, expon);
    T->next = *P;
    T->prev = (*P)->prev;
    (*P)->prev = T;
    if (T->prev != NULL) {
        T->prev->next = T;
    }
    *P = T;
}

// Function to read a polynomial
void ReadPoly(Polynomial *P) {
    double coef;
    int expon;
    *P = NewNode(0, -1);
    (*P)->prev = *P;

    printf("Enter the coefficient and exponent of each term (e.g. 2 3), enter -1 -1 to end:\n");
    scanf("%lf %d", &coef, &expon);
    while (expon != -1) {
        Attach(coef, expon, P);
        scanf("%lf %d", &coef, &expon);
    }
}

// Function to display a polynomial
void PrintPoly(Polynomial P) {
    P = P->prev;
    while (P->next != NULL) {
        P = P->next;
        if (P->coef > 0 && P->prev->expon != -1) {
            printf("+");
        }
        if (P->expon == 0) {
            printf("%.2lf ", P->coef);
        }
        else if (P->expon == 1) {
            printf("%.2lfx ", P->coef);
        }
        else {
            printf("%.2lfx^%d ", P->coef, P->expon);
        }
    }
    printf("\n");
}

// Function to add two polynomials
void AddPoly(Polynomial P1, Polynomial P2, Polynomial *P3) {
    Polynomial T1 = P1->prev, T2 = P2->prev;

    *P3 = NewNode(0, -1);
    (*P3)->prev = *P3;

    while (T1->next != NULL && T2->next != NULL) {
        if (T1->expon > T2->expon)
                {
        Attach(T1->coef, T1->expon, P3);
        T1 = T1->next;
    }
    else if (T1->expon < T2->expon) {
        Attach(T2->coef, T2->expon, P3);
        T2 = T2->next;
    }
    else {
        double coef = T1->coef + T2->coef;
        if (coef != 0) {
            Attach(coef, T1->expon, P3);
        }
        T1 = T1->next;
        T2 = T2->next;
    }
}

// Attach remaining terms from P1 or P2
while (T1->next != NULL) {
    Attach(T1->coef, T1->expon, P3);
    T1 = T1->next;
}
while (T2->next != NULL) {
    Attach(T2->coef, T2->expon, P3);
    T2 = T2->next;
}
}

// Function to multiply two polynomials
void MultPoly(Polynomial P1, Polynomial P2, Polynomial *P4) {
    Polynomial T1 = P1->prev, T2 = P2->prev;

    *P4 = NewNode(0, -1);
    (*P4)->prev = *P4;

    while (T1->next != NULL) {
        T1 = T1->next;
        Polynomial T3 = NewNode(0, -1);
        T3->prev = T3;
        while (T2->next != NULL) {
            T2 = T2->next;
            double coef = T1->coef * T2->coef;
            int expon = T1->expon + T2->expon;
            Attach(coef, expon, &T3);
        }
        T2 = P2->prev;
        AddPoly(*P4, T3, P4);
    }
}

int main() {
    Polynomial P1, P2, P3, P4;

    printf("Enter the first polynomial:\n");
    ReadPoly(&P1);

    printf("Enter the second polynomial:\n");
    ReadPoly(&P2);

    printf("The first polynomial is:\n");
    PrintPoly(P1);

    printf("The second polynomial is:\n");
    PrintPoly(P2);

    printf("The sum of the two polynomials is:\n");
    AddPoly(P1, P2, &P3);
    PrintPoly(P3);

    printf("The product of the two polynomials is:\n");
    MultPoly(P1, P2, &P4);
    PrintPoly(P4);

    return 0;
}


