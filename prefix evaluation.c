//ctype = classify into individual characters
//-*23+45*6
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX 100

int stack[MAX];
int top=-1;

void push(int x)
{
    stack[++top]=x;
}

int pop()
{
    return stack[top--];
}

int eval(char* exp)
{
    int i;
    int op1,op2;
    int len = strlen(exp);
    for(i=len-1;i>=0;i--)
    {
        if(isdigit(exp[i]))
            push(exp[i]-'0');
        else
        {
            op2 = pop();
            op1 = pop();
            switch(exp[i])
            {
                case '+': push(op1+op2); break;
                case '-': push(op1-op2); break;
                case '*': push(op1*op2); break;
                case '/': push(op1/op2); break;
            }
        }
    }
    return stack[top];
}

int main()
{
    char exp[MAX];
    printf("Enter a prefix expression: ");
    scanf("%s", exp);
    printf("Result: %d\n", eval(exp));
    return 0;
}

