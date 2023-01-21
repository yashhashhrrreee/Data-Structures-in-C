#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[50];
    int roll;
    struct student *next;
    struct student *prev;
} *start = NULL, *last = NULL;

void create(char name[], int roll) {
    struct student *new_node;
    new_node = (struct student *)malloc(sizeof(struct student));

    strcpy(new_node->name, name);
    new_node->roll = roll;
    new_node->next = NULL;

    if (start == NULL) {
        start = new_node;
        last = new_node;
    } else {
        last->next = new_node;
        last = new_node;
    }
}

void display() {
    struct student *temp;
    if (start == NULL) {
        printf("No students records found\n");
        return;
    }
    temp = start;
    printf("Student records:\n");
    while (temp != NULL) {
        printf("Name: %s\tRoll: %d\n", temp->name, temp->roll);
        temp = temp->next;
    }
}

void display_reverse() {
    struct student *temp;
    if (start == NULL) {
        printf("No students records found\n");
        return;
    }
    temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Student records in reverse:\n");
    while (temp != NULL) {
        printf("Name: %s\tRoll: %d\n", temp->name, temp->roll);
        temp = temp->prev;
    }
}

void insert_at_start(char name[], int roll) {
    struct student *new_node;
    new_node = (struct student *)malloc(sizeof(struct student));

    strcpy(new_node->name, name);
    new_node->roll = roll;
    new_node->next = start;
    start = new_node;
}

void insert_at_last(char name[], int roll) {
    struct student *new_node;
    new_node = (struct student *)malloc(sizeof(struct student));

    strcpy(new_node->name, name);
    new_node->roll = roll;
    new_node->next = NULL;
    last->next = new_node;
    last = new_node;
}

void insert_in_between(char name[], int roll, int position) {
    struct student *new_node, *temp;
    int i;

    new_node = (struct student *)malloc(sizeof(struct student));

    strcpy(new_node->name, name);
    new_node->roll = roll;

    temp = start;
    for (i = 1; i < position - 1; i++) {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void delete(int roll) {
    struct student *temp, *prev;
    temp = start;
    while (temp->roll != roll) {
prev = temp;
temp = temp->next;
}
if (temp == start) {
start = start->next;
} else {
prev->next = temp->next;
}
free(temp);
printf("Record deleted successfully\n");
}

int main() {
int choice, roll;
char name[50];
while (1) {
printf("1. Display all students information\n");
printf("2. Display information in reverse order\n");
printf("3. Insert new students record in between\n");
printf("4. Insert new students record at last\n");
printf("5. Insert new students record at start\n");
printf("6. Delete existing students record\n");
printf("7. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
display();
break;
case 2:
display_reverse();
break;
case 3:
printf("Enter the name and roll of the student: ");
scanf("%s%d", name, &roll);
printf("Enter the position to insert the record: ");
int position;
scanf("%d", &position);
insert_in_between(name, roll, position);
break;
case 4:
printf("Enter the name and roll of the student: ");
scanf("%s%d", name, &roll);
insert_at_last(name, roll);
break;
case 5:
printf("Enter the name and roll of the student: ");
scanf("%s%d", name, &roll);
insert_at_start(name, roll);
break;
case 6:
printf("Enter the roll of the student to delete: ");
scanf("%d", &roll);
delete(roll);
break;
case 7:
exit(0);
break;
default:
printf("Invalid choice\n");
}
}
return 0;
}

