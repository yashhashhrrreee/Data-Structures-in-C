#include<stdio.h>
#include<stdlib.h>


struct node
{
    int key;
    struct node* left;
    struct node* right;
};

struct Stack
{
    int size;
    int top;
    struct node** array;
};

struct node* newNode(int item)
{
    struct node *temp =  (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}


struct node* insert(struct node* Node, int key)
{
    if (Node == NULL)
        return newNode(key);

    if (key < Node->key)
        Node->left  = insert(Node->left, key);
    else if (key > Node->key)
        Node->right = insert(Node->right, key);

    return Node;
}

struct Stack* createStack(int size)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (struct node**) malloc(stack->size * sizeof(struct node*));
    return stack;
}


int isFull(struct Stack* stack)
{
    return stack->top - 1 == stack->size;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

void push(struct Stack* stack,struct node* Node)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = Node;
}

struct node* pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

struct node* peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}

void postOrderIterative(struct node* root)
{
    if (root == NULL)
        return;

    struct Stack* stack = createStack(50);
    do
    {
        while (root)
        {
            if (root->right)
                push(stack, root->right);
            push(stack, root);

            root = root->left;
        }

        root = pop(stack);

        if (root->right && peek(stack) == root->right)
        {
            pop(stack);
            push(stack, root);
            root = root->right;
        }
        else
        {
            printf("%d ", root->key);
            root = NULL;
        }

    }
    while (!isEmpty(stack));
}

struct node** createQueue(int *front, int *rear)
{
    struct node **queue =(struct node**)malloc(sizeof(struct node*) * 50);

    *front = *rear = 0;
    return queue;
}

void enQueue(struct node **queue, int *rear, struct node *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}

struct node *deQueue(struct node **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}

int isQEmpty(int* front,int* rear)
{
    return(*front == *rear);
}

void printLevelOrder(struct node* root)
{
    if (root == NULL)
        return;

    int rear,front,nodeCount;

    struct node **queue = createQueue(&front, &rear);

    enQueue(queue,&rear,root);

    while (!isQEmpty(&front,&rear))
    {
        nodeCount=rear-front;

        while(nodeCount>0)
        {
            struct node* Node=deQueue(queue,&front);

            printf("%d ", Node->key);

            if (Node->left)
                enQueue(queue, &rear, Node->left);

            if (Node->right)
                enQueue(queue, &rear, Node->right);

            nodeCount--;
        }
        printf("\n");
    }
}


void printLeaf(struct node* p)
{

    struct Stack* s = createStack(50);

    while (1)
    {
        if (p)
        {
            push(s,p);
            p = p->left;
        }

        else
        {
            if (isEmpty(s))
                break;
            else
            {

                if (peek(s)->right == NULL)
                {
                    p = pop(s);

                    if (p->left == NULL)
                        printf("%d ", p->key);
                }

                while (p == peek(s)->right)
                {
                    p = pop(s);

                    if (isEmpty(s))
                        break;
                }

                if (!isEmpty(s))
                    p = peek(s)->right;
                else
                    p = NULL;
            }
        }
    }
    printf("\n");
}




int main()
{
    struct node* root=NULL;
    int ch=1;
    int treeElement,choice;

    printf("Please enter elements to construct BST starting with root.\n");
    while(ch==1)
    {
        printf("\nEnter element :");
        scanf("%d",&treeElement);
        root=insert(root,treeElement);
        printf("\nEnter another element?[0/1] :");
        scanf("%d",&ch);
    }

    printf("\n\nBST CREATED!");

    do
    {

        printf("\n\n------------------MENU------------------\n\n");
        printf("\nEnter 1 to display postorder traversal of tree.");
        printf("\nEnter 2 to display tree level wise.");
        printf("\nEnter 3 to display leaf nodes of tree.");
        printf("\nEnter 0 to exit.");

        printf("\nEnter choice:");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            postOrderIterative(root);
            break;

        case 2:
            printLevelOrder(root);
            break;

        case 3:
            printLeaf(root);
            break;

        default:
            break;

        }
    }
    while(choice);

    printf("\nPROGRAM EXITED!");

    getch();

    return 0;

}
