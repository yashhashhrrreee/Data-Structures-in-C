#include <stdio.h>
#include <string.h>

int i,j=0,length;
char fullname[100],result[100];
struct stack
{
char stk[100];
int top;
}s;
int main()
{
    printf("Enter full name (name middlename surname): ");
    gets(fullname);
    length=strlen(fullname);
    push(' ');
pushinstk();
    for(j=0;j<length-1,i<length;j++,i++)
    result[i]=fullname[j];
    printf("Full name in (Surname name middlename) format is: ");
    puts(result);
    return 0;
}

void push(char value)
{
s.top++;
s.stk[s.top] = value;
}

void pop()
{
s.top--;
}

int pushinstk()
{
   for(i=length-1;i>=0;i--)
    {
        if(fullname[i]!=' ')
            push(fullname[i]);
        else
            break;
    }
    for(i=0;i<length-1;i++)
    {
        if(s.top!=0)
        {
            result[i]=s.stk[s.top];
            pop();
        }
        else
            break;
    }
}