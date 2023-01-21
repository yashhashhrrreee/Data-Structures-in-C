#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int x[MAX];
int count = 0;

void push(int x, int *top, int stack_arr[])
{
        if(*top == (MAX-1))
                printf("Stack Overflow\n");
        else
        {
                *top=*top+1;
                stack_arr[*top] = x;
        }
}

int pop(int *top, int stack_arr[])
{
        int x;
        if(*top == -1)
        {
                printf("Stack Underflow\n");
                exit(1);
        }
        else
        {
                x = stack_arr[*top];
                *top=*top-1;
        }
        return x;
}

void DecToBin(int num)
{
        int stack[MAX], top=-1, rem,i=0;
        while(num!=0)
        {
                rem = num % 2;
                push(rem, &top, stack);
                num/=2;
        }
        printf("\nYour password is : \n");
        while(top!=-1)
        {
            x[i] = pop(&top, stack);
            // printf( "%d", x[i]);
			count++;
            i ++;
        }
        printf("\n");
}

int room1()
{
    int num,i=0;
    printf("\You are now in Room 1\n");
    num = room2();
    printf("\nExited Room 1\n");
	while(i != count)
	{
    	printf("%d",x[i]);
		i++;
	}
    printf("\ntreasure open\n");
    return num;
}

int room2()
{
    int num;
    printf("\nYou are now in room 2\n");
    num = room3();
    printf("\nExited Room 2\n");

    return num;
}

int room3()
{
    int num;
    printf("\nYou are now in room 3\n");
    num = room4();
    printf("\nExited Room 3\n");
    return num;
}

int room4()
{
    int num;
    printf("\nYou are now in Room 4\n");
    num = room5();
    printf("\nExited Room 4\n");
    return num;
}

int room5()
{
    int num;
	int arr[MAX];
    printf("\nYou are now in room 5\n");


    printf("\nEnter an integer : \n");
    scanf("%d",&num);
	// arr[] =
	DecToBin(num);
    printf("\nExited Room 5\n");

    return num;
}

void main()
{
    int num;
    num = room1();

}
