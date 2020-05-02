#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    int coef,expo;
    struct node* next;
};

struct node* insertpoly(struct node* head,int c,int e)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coef=c;
    newnode->expo=e;
    
    if( head == NULL )
    {            // for inserting the first node..
        newnode->next=NULL;
        return newnode;
    }
    
    struct node* prev,* curr;
    prev=curr=head;
    
    while( curr!=NULL && (curr->expo)>e )
    {
        prev=curr;
        curr=curr->next;
    }
    if( curr == head )
    {            // for inserting before the first node...
        newnode->next = curr;
        return newnode;
    }
    else if( curr == NULL ) 
    {        //for inserting after the last node....
        prev->next = newnode;
        newnode->next = NULL;
    }
    else
    {
        newnode->next = curr;
        prev->next = newnode;
    }
    return head;
}

float polyEval( struct node *start, int x )
{
	struct node *ptr;
	float sum = 0.0;
	for( ptr = start; (ptr); ptr=ptr->next )
	{
		sum = sum + ( ptr->coef)*pow( x, (ptr->expo) );
	}
	return sum;
}

int main()
{
	int a,b,n,i;
	struct node *head = NULL;
	
	printf("Enter the no of terms of polynomial 1..");
	scanf("%d",&n);
	printf("\nEnter the polynomial..");
    	for( i=0; i<n; i++ )
    	{
      	printf("\nEnter the coefficient and exponent of the term..");
      	scanf( "%d%d", &a, &b );
      	head = insertpoly( head, a , b );
    	}
    	
    	printf("\n\t enter the value of x: ");
    	int x;
    	scanf("%d", &x);
    	float sum = polyEval( head, x );
    	
    	printf("\n\t the evaluated value of polynomial is : %f", sum );
    	return 0;
}
