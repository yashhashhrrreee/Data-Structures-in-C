/*
* C Program to concatenate two strings using strcpy function
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>

int main(){
    char destination[100], source[100];
    printf("Enter first string \n");
    gets(destination);
    printf("Enter second string \n");
    gets(source);
    /*
     * char *strcat(char *destination, const char *source)
     * Concatenates source at the end of destination
     */
    strcat(destination, source);

    printf("Concatenated String: %s \n", destination);

    getch();
    return 0;
}
