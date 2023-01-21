#include <stdio.h>
#include <stdlib.h>

struct student {
    int roll_no;
    char name[20];
    float marks;
    struct student *prev;
    struct student *next;
};

struct student *start = NULL;
struct student *last = NULL;

void create_list(int roll, char* name, float marks) {
    struct student *new_student;
    new_student = (struct student*)malloc(sizeof(struct student));

    new_student->roll_no = roll;
    strcpy(new_student->name, name);
    new_student->marks = marks;

    if(start == NULL) {
        new_student->next = new_student;
        new_student->prev = new_student;
        start = new_student;
        last = new_student;
    } else {
        last->next = new_student;
        new_student->prev = last;
        new_student->next = start;
        start->prev = new_student;
        last = new_student;
    }
}

void display_list() {
    struct student *temp;
    if(start != NULL) {
        temp = start;
        do {
            printf("Roll Number: %d\n", temp->roll_no);
            printf("Name: %s\n", temp->name);
            printf("Marks: %.2f\n\n", temp->marks);
            temp = temp->next;
        } while(temp != start);
    } else {
        printf("List is empty.\n");
    }
}

void display_reverse() {
    struct student *temp;
    if(last != NULL) {
        temp = last;
        do {
            printf("Roll Number: %d\n", temp->roll_no);
            printf("Name: %s\n", temp->name);
            printf("Marks: %.2f\n\n", temp->marks);
            temp = temp->prev;
        } while(temp != last);
    } else {
        printf("List is empty.\n");
    }
}

void insert_start(int roll, char* name, float marks) {
    struct student *new_student;
    new_student = (struct student*)malloc(sizeof(struct student));

    new_student->roll_no = roll;
    strcpy(new_student->name, name);
    new_student->marks = marks;

    new_student->prev = last;
    new_student->next = start;
    start->prev = new_student;
    last->next = new_student;
    start = new_student;
}

void insert_end(int roll, char* name, float marks) {
    create_list(roll, name, marks);
}

void insert_between(int roll, char* name, float marks, int location) {
    struct student *new_student;
    new_student = (struct student*)malloc(sizeof(struct student));

    new_student->roll_no = roll;
    strcpy(new_student->name, name);
    new_student->marks = marks;
    int i;
struct student *temp;
temp = start;
for(i = 0; i < location-1; i++) {
    temp = temp->next;
    if(temp == start) {
        printf("Invalid location!\n");
        return;
    }
}
new_student->prev = temp;
new_student->next = temp->next;
temp->next->prev = new_student;
temp->next = new_student;
}
void delete_node(int location) {
int i;
struct student *temp;
temp = start;
for(i = 0; i < location-1; i++) {
temp = temp->next;
if(temp == start) {
printf("Invalid location!\n");
return;
}
}
if(temp == start) {
last->next = temp->next;
temp->next->prev = last;
start = temp->next;
free(temp);
} else if(temp == last) {
last->prev->next = start;
start->prev = last->prev;
last = last->prev;
free(temp);
} else {
temp->prev->next = temp->next;
temp->next->prev = temp->prev;
free(temp);
}
}

int main() {
create_list(1, "Alice", 85.5);
create_list(2, "Bob", 90.0);
create_list(3, "Charlie", 92.5);
create_list(4, "David", 88.0);
printf("Original List:\n");
display_list();
printf("\nReverse List:\n");
display_reverse();

insert_start(5, "Eve", 95.0);
printf("\nAfter inserting at start:\n");
display_list();

insert_end(6, "Frank", 87.5);
printf("\nAfter inserting at end:\n");
display_list();

insert_between(7, "Grace", 80.0, 4);
printf("\nAfter inserting between:\n");
display_list();

delete_node(3);
printf("\nAfter deleting node:\n");
display_list();

return 0;
}
