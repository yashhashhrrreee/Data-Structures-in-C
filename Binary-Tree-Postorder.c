#include<stdio.h>
#include<stdlib.h>
#define size 30

struct tree 
{
	int data;
	struct tree *left,*right;
};

struct tree *root=NULL;

int rear=-1;
int front=-1;
struct tree *queue[size];

void create()
{
	struct tree *newNode=malloc(sizeof(struct tree));
	printf("\nEnter the data of root : ");
	scanf("%d",&newNode->data);
	root=newNode;
	root->left=NULL;
	root->right=NULL;
	//printf("%d",root->data);
}

void createtree()
{
	int opt,flag;
	struct tree *p=root;
	struct tree *newNode=malloc(sizeof(struct tree));
	printf("\nEnter the data of node : ");
	scanf("%d",&newNode->data);
	flag =0;
	while(flag!=1)
	{
		if(flag==1)
		p=root;
		printf("\nWhere to add w.r.t %d ...\n(1 for left and 2 for right ) : ",p->data);
		scanf("%d",&opt);
		if(opt==1)
		{
			if(p->left==NULL)
			{
				//printf("%d",newNode->data);
				p->left=newNode;
				flag =1;
			}
			else
			{
				p=p->left;
				flag=0;
			}
		}
		else 
		{
			if(p->right==NULL)
			{
				p->right=newNode;
				flag =1;
			}
			else
			{
				p=p->right;
				flag=0;
			}
		}
		
	}
	newNode->left=NULL;
	newNode->right=NULL;
}

void add(struct tree *);
struct tree *dele();
int q_empty();
struct tree *pop();
int stack_empty();
struct tree *stack[size];
int top=-1;
void push(struct tree *item);
struct tree *pop();

void levelwise(struct tree *p)
{
	
	printf("%d ",p->data);
	do
	{
		if(p->left!=NULL)
		add(p->left);
		if(p->right!=NULL)
		add(p->right);
		p=dele();
		printf("%d\t",p->data);
	}while(!q_empty() && p!=NULL);
}

void leafnode(struct tree *p)
{
	int count=0;
	do
	{
		if(p->left!=NULL)
		add(p->left);
		if(p->right!=NULL)
		add(p->right);
		p=dele();
		if(p->left==NULL && p->right==NULL)
		{
			printf("%d\t",p->data);
			count++;
	}
	}while(!q_empty() && p!=NULL);
	printf("\n%d",count);
}

void add(struct tree *ch)
{
	if(rear==size-1)
	printf("\nStack overflow");
	else
	{
		if(front==-1)
		front=0;
		rear++;
		queue[rear]=ch;
	}
}

struct tree *dele()
{
	struct tree *ch;
	if(q_empty())
	{
		printf("\nQueue Overflow");
		//return;
    }
	else
	ch=queue[front];
	front++;
	return ch;
}

int q_empty()
{
	if(front>rear)
	return 1;
	else
	return 0;
}

void push(struct tree *item)
{
        if(top==(size-1))
        {
                printf("Stack Overflow\n");
                //return;
        }
        top=top+1;
        stack[top]=item;
}

struct tree *pop()
{
        struct tree *item;
        if(top==-1)
        {
                printf("Stack Underflow....\n");
                exit(1);
        }
        item=stack[top];
        top=top-1;
        return item;
}

int stack_empty()
{
        if(top==-1)
                return 1;
        else
                return 0;
}

void postorder(struct tree *root)
{
        struct tree *ptr = root;
        struct tree *q;

        if( ptr==NULL )
        {
                printf("Tree is empty\n");
                return;
        }
        q = root;
        while(1)
        {
                while(ptr->left!=NULL)
                {
                        push(ptr);
                        ptr=ptr->left;
                }

                while( ptr->right==NULL || ptr->right==q )
                {
                        printf("%d  ",ptr->data);
                        q = ptr;
                        if( stack_empty() )
                                return;
                        ptr = pop();
                }
                push(ptr);
                ptr = ptr->right;
        }
        printf("\n");
}

int main()
{
	
		
	int choice;
	create();
	do
	{
		printf("\nEnter your choice :");
		printf("\n1.Insert node\n2.Postorder traversal\n3.Display a tree levelwise\n4.Display leaf nodes of a tree\n5.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				createtree();
				//count++;
				break;
			case 2:
				postorder(root);
				break;
			case 3:
				levelwise(root);
				break;
			case 4:
				leafnode(root);
				break;
			default:
				printf("\nInvalid input...!");
		}
		
	}while(choice!=5);
	
}
