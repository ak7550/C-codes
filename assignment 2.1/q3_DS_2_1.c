#include<stdio.h>
#include<stdlib.h>

struct Stack
{
	char *str;
	int top;
};

struct Stack obj;

void Push( char );
void Pop();

int main()
{
	char str1[100];
	
	printf("\n\t enter the string of parenthesis: ");
	scanf( "%[^\n]%*c", str1 );
	
	int k;
	for( k=0; str1[k] != '\0'; k++ );
	obj.str = (char*) malloc( sizeof( char[k] ) );
	obj.top = -1;
	
	int i;
	
	for( i=0; i<k; i++ )
	{
		if( str1[i] == '(' )
			Push( str1[i] );
			
		else if( str1[i] == ')' )
			Pop();
		
		else
			continue;
	}
	
	if( obj.top == -1 )
		printf("\n\t the string is well formed!!!!!!");
	else
		printf("\n\t it is not well formed!!!!!");
	return 0;
}

void Push( char ch )
{
	obj.top = obj.top + 1;
	obj.str[ obj.top ] = ch;
}

void Pop()
{
	if( obj.top == -1 )
	{
		printf("\n\t underflow!!!!!!");
		return;
	}
	obj.top = obj.top - 1;
}
