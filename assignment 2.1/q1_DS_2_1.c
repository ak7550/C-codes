#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Tree
{
	int data;
	struct Tree *left;
	struct Tree *right;
};

struct Tree* Insert(int key)
{
    struct Tree* leaf = (struct Tree*)malloc(sizeof(struct Tree));
    leaf->data = key;
    leaf->left = NULL;
    leaf->right = NULL;
 
    return (leaf);
}

unsigned int CountLeafNodes( struct Tree *leaf )
{
	if( leaf == NULL )
		return 0;
	if( leaf->left == NULL && leaf->right == NULL )
		return 1;
	else
		return (CountLeafNodes( leaf->left ) + CountLeafNodes( leaf->right ) );
}

int Size( struct Tree *leaf)  
{  
    if( leaf == NULL )  
        return 0;  
    else
        return( Size(leaf->left) + 1 + Size(leaf->right) );  
} 

int main()
{
	struct Tree *Root = NULL;
	
	Root = Insert(25);
      Root->left = Insert(27);
      Root->right = Insert(19);
      Root->left->left = Insert(17);
      Root->left->right = Insert(91);
      Root->right->left = Insert(13);
      Root->right->right = Insert(55);
	
	printf("\n\t the size of Tree is %d",Size(Root) );
	printf("\n\t the no. of leaf nodes is %d", CountLeafNodes( Root ) );
	return 0;
}
