/* Write a program to implement multiple stack i.e.
 two stacks using array and perform following operations ion it.
 A. Push, B. Pop, C. StackFull,  D. StackEmpty, E. Display full stack,
 F. Display selected Stack.
##########################CODE##########################################*/
#include<stdio.h>

#define MAX_X 50
#define MAX_Y 50

struct stac
{
int stk[100];
int top;
}x,y;

void push_x(int item)
{
x.top++;
x.stk[x.top] = item;
}

void pop_x()
{
x.top--;
}

void push_y(int item)
{
y.top++;
y.stk[y.top] = item;
}

void pop_y()
{
y.top--;
}

int isStackFull_x()
{
    if(x.top>=(MAX_X-1))
	{
        return 1;
	}
    else
        return 0;
}

int isStackFull_y()
{
    if(y.top<=(MAX_Y))
	{
        return 1;
	}
    else
        return 0;
}

int isStackEmpty_x()
{
    if(x.top==-1)
	{
		return 1;
	}
    else
        return 0;
}

int isStackEmpty_y()
{
    if(y.top==-1)
	{
		return 1;
	}
    else
        return 0;
}

void display_x()
{
	int i;
	if(isStackEmpty_x())
	{
		printf("Stack 1 is Empty");
	}
	else
	{
        for(i=0;i<=x.top;i++)
	    {
           printf("%d\t",x.stk[i]);
        }
	        printf("\n");
	}
}

void display_y()
{
	int i;
	if(isStackEmpty_y())
	{
        printf("Stack 2 is Empty");
    }
	else
	{
        for(i=0;i<=y.top;i++)
	   {
		printf("%d\t",y.stk[i]);
	   }
	   printf("\n");
	}
}

int main()
{
    int choice,n=0;
    x.top=-1;
    y.top=-1;
    do
        {
            printf("\n1.Push(Stack 1)\n2.Push(Stack 2)");
            printf("\n3.Pop(Stack 1)\n4.Pop(Stack 2)");
            printf("\n5.Check if stack 1 is full\n6.Check if stack 2 is full");
            printf("\n7.Check if stack 1 is empty\n8.Check if stack 2 is empty");
            printf("\n9.Display Stack 1\n10.Display Stack 2");
            printf("\n11.Exit");
            printf("\n\nEnter Choice : ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                    {
                        printf("enter the value to be pushed : ");
                        scanf("%d",&n);
                        push_x(n);
                    }
                break;

                case 2:
                    {
                        printf("enter the value to be pushed : ");
                        scanf("%d",&n);
                        push_y(n);
                    }
                break;

                case 3:
                    pop_x();
                break;

                case 4:
                    pop_y();
                break;

                case 5:

                    if(isStackFull_x())
                        printf("Stack 1 is Full");
                    else
                        printf("Stack 1 is not full");
                    break;

                case 6:
                    if(isStackFull_y())
                        printf("Stack 2 is full");
                    else
                        printf("Stack 2 is not full");
                    break;
                case 7:
                    if(isStackEmpty_x())
                        printf("Stack 1 is empty");
                    else
                        printf("Stack 1 is not empty");
                    break;
                case 8:
                    if(isStackEmpty_y())
                        printf("Stack 2 is empty");
                    else
                        printf("Stack 2 is not empty");
                    break;
                case 9:
                    display_x();
                    break;
                case 10:
                    display_y();
                    break;
                case 11:
                    break;
                default:
                    printf("Enter a valid option");
            }
        }while(choice!=11);
return 0;
}