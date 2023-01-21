#include <stdio.h>
//#include <alloc.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 10

typedef struct binarysearchtree{
    int info;
    struct binarysearchtree *left;
    struct binarysearchtree *right;
}BST;

/*Allocates the memory*/
BST *create();
/*Makes a new node*/
BST *makenode(int);
/*Inserts a new node in a BST using recursive definition*/
BST *insert(BST *,BST *);

/*Traverses BST in postorder using iterative definition*/
void iterativepostorder(BST *);


/*Traverses BST in preorder by iterative definition*/
void iterativepreorder(BST *);

/*Traverses BST in inorder using iterative definition*/
void iterativeinorder(BST *);

/*Generates a duplicate copy of BST*/
void clone(BST *);


/*Global stack declarations used for
postorder iterative traversals*/
struct pstack{;
    BST *tree;
    int visitedleft,visitedright;
}pstk[MAX];


/*Global declaration of top*/
int top=-1;
void ppush(struct pstack pstk[],BST *t,int VL,int VR)
{
    if(top==MAX-1)
        {printf('\nStack Overflow…!');
        return;
        }
    top++;
    pstk[top].tree = t;
    pstk[top].visitedleft=VL;
    pstk[top].visitedright=VR;
}


/*Pop the topmost element from the stack*/
struct pstack *ppop(struct pstack *pstk)
{struct pstack *temp;
    if(top==-1)
        {printf('\nStack Underflow…!');
        return NULL;
        }
    temp=&pstk[top];
    top;
return temp;
}
/*Checks & returns the value of top*/
int pempty()
{return(top==-1);
}



/*Iterative Postorder Traversal*/
void iterativepostorder(BST *root)
{
    struct pstack *temp;
    BST *p=root;
    while(1)
        {while(p!=NULL)
            {ppush(pstk,p,1,0);
        p=p->left;
        }
    if(pempty())
        return;
        temp=ppop(pstk);
    if(temp->visitedleft==1 && temp->visitedright==1)
        printf('%dt',temp->tree->info);
    else
        {ppush(pstk,temp->tree,temp->visitedleft,1);
        p=temp->tree->right;
    }
}
}


/*Global stack declaration used for iterative traversals*/
typedef struct stack
{int top;
BST *items[MAX];
}stk;
/*Checks whether the stack is empty or not*/
int empty(stk *s)
    {return(s->top==-1);
}
/*Push a node of BST into the stack*/
void push(stk *s, BST *t)
    {if(s->top==MAX-1)
    {printf('\nStack Overflow…!');
    return;
    }
    s->items[++(s->top)]=t;
}
/*Pops/returns a node of BST from the top of the stack*/
BST *pop(stk *s)
    {if(s->top==-1)
    {printf('\nStack Underflow…!');
    return NULL;
    }
return(s->items[(s->top)]);
}


/*Iterative Preorder Traversal*/
void iterativepreorder(BST *root)
    {stk s;
    BST *p=root;
    s.top=-1;
    do
    {
    while(p!=NULL)
    {printf('%dt',p->info);
    push(&s,p);
    p=p->left;
    }
    if(!empty(&s))
    {p=pop(&s);
    p=p->right;
    }
    }while(!empty(&s) || p!=NULL);
}
/*Iterative Inorder Traversal*/
void iterativeinorder(BST *root)
    {stk s;
    BST *p=root;
    s.top=-1;
    do
    {while(p!=NULL)
    {push(&s,p);
    p=p->left;
    }
    if(!empty(&s))
    {p=pop(&s);
    printf('%dt',p->info);
    p=p->right;
    }
    }while(!empty(&s) || p!=NULL);
}


void iterativeinorder(BST *root)
    {stk s;
    BST *p=root;
    s.top=-1;
    do
    {while(p!=NULL)
    {push(&s,p);
    p=p->left;
    }
    if(!empty(&s))
    {p=pop(&s);
    printf('%dt',p->info);
    p=p->right;
    }
    }while(!empty(&s) || p!=NULL);
}

/*Creating clone of a given tree*/
BST *newroot=NULL; /*global definition of root of new tree*/
void clone(BST *root)
{
BST *temp;
if(root)
    {printf('nMaking node %d',root->info);
    temp=makenode(root->info);
    newroot=insert(newroot,temp);
    clone(root->left);
    clone(root->right);
    }
}



int main(){

    int ch,x;
    BST *newnode,*root=NULL;



    printf('\nNon-Recursive/Iterative Menu');
    printf('1. Insertion');
    printf('2. Inorder traversal');
    printf('3. Preorder traversal');
    printf('4. Postorder traversa');
    printf('5. Copy a tree');
    printf('6. Return');
    printf('nEnter your choice: ');
    scanf('%d',&ch);
    switch(ch)
    {case 1:
        printf('\nEnter the number: ');
        scanf('%d',&x);
        newnode=makenode(x);
        root=iterativeinsert(root,newnode);
    break;

    case 2:
        iterativeinorder(root);
    break;

    case 3:
        iterativepreorder(root);
    break;

    case 4:
        iterativepostorder(root);
    break;

    case 5:clone(root);
        printf('nDisplaying original BST-inorder');
        inorder(root);
        printf('nDisplaying its clone-inorder');
        inorder(newroot);
        break;

    case 6:
        exit(0);


    default:printf('nInvalid choice…!');
}

}