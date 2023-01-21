#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>

struct node
{
   int data;
   struct node *right;
   struct node *left;
};

struct node *tree;
struct node *create()
{
   struct node *ptr;
   int val;
   printf("\t\tENTER VALUE(-1 for no data):");
   scanf("%d",&val);

   if(val==-1)
     return NULL;
   ptr=(struct node*)malloc(sizeof(struct node));
   ptr->data=val;

   printf("\t\tENTER LEFT OF %d:\n",val);
   ptr->left=create();

   printf("\t\tENTER RIGHT OF %d:\n",val);
   ptr->right=create();

   return ptr;
}
void inorder(struct node*temp)
{
   int top=0;
   struct node *s[20],*pt=temp;
   s[0]=NULL;
   while(pt!=NULL)
   {
      top++;
      s[top]=pt;
      pt=pt->left;
   }
   pt=s[top];
   top--;
   while(pt!=NULL)
   {
      printf("%d\t",pt->data);
      if(pt->right!=NULL)
      {
	 pt=pt->right;
	 while(pt!=NULL)
	 {
	     top++;
	     s[top]=pt;
	     pt=pt->left;
	 }
      }
      pt=s[top];
      top--;
   }
}
void preorder(struct node *temp)
{
  int top=0;
  struct node *s[20],*pt=temp;
  s[0]=NULL;
  while(pt!=NULL)
  {
       printf("%d\t",pt->data);
       if(pt->right!=NULL)
       {
	    top++;
	    s[top]=pt->right;
       }
       if(pt->left!=NULL)
       pt=pt->left;
       else
       {
	  pt=s[top];
	  top--;
       }
  }
}
void postorder(struct node *temp)
{
   int a[20],c,i=0,top=0;
   struct node *s[20],*pt=temp;
   s[0]=NULL;
   while(pt!=NULL)
   {
       a[i++]=pt->data;
       c++;
       if(pt->left!=NULL)
       {
	   top++;
	   s[top]=pt->left;
       }
       if(pt->right!=NULL)
       pt=pt->right;
       else
       {
	   pt=s[top];
	   top--;
       }
   }
   for(c=i-1;c>=0;c--)
   printf("\t%d",a[c]);
}

struct node* cloneBinaryTree(struct node *ptr){
    if(ptr == NULL)
        return NULL;
    struct node* newNode = create();
    newNode->left = cloneBinaryTree(ptr->left);
    newNode->right = cloneBinaryTree(ptr->right);
    return newNode;
}

void inOrderTraversal(struct node *nodeptr){
    if(nodeptr != NULL){
        inOrderTraversal(nodeptr->left);
        printf("%d ", nodeptr->data);
        inOrderTraversal(nodeptr->right);
    }
}

int main()
{
   int choice;
   struct node *tree;
   struct node *clone, *ptr = create();
   do
   {
       printf("\n\n------MAIN MENU------\n");
       printf("1.INSERT\n");
       printf("2.IN-ORDER TRAVERSAL\n");
       printf("3.PRE-ORDER TRAVERSAL\n");
       printf("4.POST-ORDER TRAVERSAL\n");
       printf("5.COPY\n");
       printf("6.EXIT\n");
       printf("ENTER YOUR CHOICE:");
       scanf("%d",&choice);
       switch(choice)
       {
	    case 1:tree=create();
	    break;

	    case 2:inorder(tree);
	    break;

	    case 3:preorder(tree);
	    break;

	    case 4:postorder(tree);
	    break;

	    case 5:
	    clone = cloneBinaryTree(ptr);
	    printf("\nClone Tree\n");
        inOrderTraversal(clone);
	    break;

	    case 6:exit(0);
       }

   }while(choice!=6);
    return 0;
}







