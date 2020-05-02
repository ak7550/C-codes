#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Node
{
	int val;
	struct Node *next;
};

struct Node *Start, *Start2;

struct Node *getnode( )
{
	struct Node *lnode = (struct Node*) malloc( sizeof( struct Node ) );
	lnode->val = rand()%20;
	lnode->next = NULL;
	return lnode;
}

void InsAtEnd()
{
	struct Node *lnode = getnode();
	
	if( Start == NULL )
	{
		Start = lnode;
		return;
	}
	
	struct Node *ptr;
	for( ptr=Start; (ptr); ptr=ptr->next )
	{
		if( ptr->next == NULL )
		{
			ptr->next = lnode;
			lnode->next = NULL;
		}
	}
}

void Display( struct Node *head )
{
	struct Node *ptr;
	for( ptr=head; (ptr); ptr=ptr->next )
		printf("%d ", ptr->val );
}

void Sort() 
{  
      struct Node *evenStart, *evenEnd, *oddStart, *oddEnd;
      evenStart = evenEnd = oddStart = oddEnd = NULL;
    
      struct Node *curr = Start;
    
      while( curr != NULL )
      {
     		int data = curr->val;
     		
     		if( data%2 == 0 )
     		{
     			if( evenStart == NULL )
			{
				evenStart = curr;
				evenEnd = evenStart;
			}
			else
			{
				evenEnd->next = curr;
				evenEnd = evenEnd->next;
			}
		}
		else
		{
			if( oddStart == NULL )
			{
				oddStart = curr;
				oddEnd = oddStart;
			}
			else
			{
				oddEnd->next = curr;
				oddEnd = oddEnd->next;
			}
		}
		curr = curr->next;
      }
    
      if( oddStart == NULL || evenStart == NULL )
    		return;
	else
	{
		Start = evenStart;
		evenEnd->next = NULL;
		Start2 = oddStart;
		oddEnd->next = NULL;	
	}
	Display( evenStart );
	printf("\n\t");
	Display( oddStart );
} 

int main()
{
	srand( time(0) );
	Start = Start2 = NULL;
	int i;
	for( i=0; i<10; i++ )
		InsAtEnd();
		
	printf("\n\t the list is: \n\t");
	Display( Start );
	
	printf("\n\t sorted linked lists are: \n\t");
	Sort();
	return 0;	
} 
