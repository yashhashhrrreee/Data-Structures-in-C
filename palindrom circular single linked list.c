#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(char data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

int isPalindrome()
{
    struct Node* current = head;
    int length = 0, i;
    char str[100];
    while (current != NULL)
    {
        str[length] = current->data;
        current = current->next;
        length++;
    }
    str[length] = '\0';

    for (i = 0; i < length; i++)
    {
        if (str[i] != str[length - i - 1])
            return 0;
    }
    return 1;
}

int main()
{
    char str[100];
    int i;
    printf("Enter a string: ");
    scanf("%s", str);
    for (i = 0; i < strlen(str); i++)
        insert(str[i]);

    if (isPalindrome())
        printf("The entered string is a palindrome.");
    else
        printf("The entered string is not a palindrome.");

    return 0;
}
