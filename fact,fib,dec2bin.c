#include<stdio.h>
#include<string.h>

struct stackk
{
char stk[100];
int top;
}s;

void push(char a)
{
s.top++;
s.stk[s.top] = a;
}

void pop()
{
s.top--;
}

void factorial()
{
    int n,f=1,i;
    s.top=0;
    printf("enter the number : ");
    scanf("%d",&n);
    for(i=2;i<=n;i++)
        push(i);
    for(;s.top!=0;)
    {
        f=f*s.stk[s.top];
        pop();
    }
    printf("the factorial of the given number is : %d",f);
}

void fibonacci()
{
    int t1=0,t2=1,i,n;
    s.top=0;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    for (i = 1; i <= n; ++i)
        {
            printf("%d, ", t1);
            push(t1 + t2);
            t1 = t2;
            t2 = s.stk[s.top];
        }
}

void decitobinary()
{
    int num,i;
    s.top=0;
    printf("Enter decimal number : ");
    scanf("%d",&num);
    while((num!=0))
        {
            push(num%2);
            num=num/2;
        }
    printf("\nthe binary conversion is : ");
    while(s.top!=0)
        {
            num=s.stk[s.top];
            pop();
            printf("%d",num);
        }
}

int main()
{
    int c,a;

    printf(" 1. factorial \n 2. fibonacci series \n 3. decimal to binary\n\n");
    scanf("%d",&c);
    switch(c)
    {
    case 1:
        {
            factorial();
            break;
        }
    case 2:
        {
            fibonacci();
            break;
        }
    case 3:
        {
            decitobinary();
            break;
        }
    default:
        printf("Not Valid");
    }

    return 0;
}