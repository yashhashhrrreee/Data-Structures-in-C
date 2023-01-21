#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
} node;

struct node *create()
{
	struct node *newnode;
	int x;
	printf("\nEnter data of tree or -1 for nothing-> ");
	scanf("%d", &x);

	if (x == -1)
		return NULL;

	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = x;

	printf("\nEnter left child of %d", x);
	newnode->left = create();

	printf("\nEnter right child of %d", x);
	newnode->right = create();

	return newnode;
}

void preorder(struct node *t)
{
	if (t != NULL)
	{
		printf("\n%d", t->data);
		preorder(t->left);
		preorder(t->right);
	}
}

int height(struct node *root)
{
	int sum;

	if (root != NULL)
	{

		int ltree = height(root->left);

		int rtree = height(root->right);
		if (ltree > rtree)
		{
			sum = ltree + 1;
			return sum;
		}
		else
		{
			sum = rtree + 1;
			return sum;
		}
	}
}
void mirror(struct node *r)
{
	if (r == NULL)
		return;
	else
	{
		struct node *temp;
		mirror(r->left);
		mirror(r->right);

		temp = r->left;
		r->left = r->right;
		r->right = temp;
	}
}

int main()
{
	int finalheight, choice;
	struct node *root;
	root = create();
	while (1)
	{
		printf("\n\nEnter your choice :\n");
		printf("\n\n1.Preorder Traversal of tree\n");
		printf("\n\n2.Height of tree\n");
		printf("\n\n3.Mirror Image\n");
		printf("\n\n4.Quit\n\n");
		scanf("%d", &choice);

		switch (choice)
		{

		case 1:
			printf("\n\nThe preorder traversal of tree is ->");
			preorder(root);
			break;

		case 2:
			printf("\n\nHeight of tree -> %d\n", height(root));
			break;

		case 3:
			mirror(root);
			break;

		case 4:
			exit(1);

		default:
			printf("\n\nInvalid choice\n");
		}
	}

	return 0;
}

