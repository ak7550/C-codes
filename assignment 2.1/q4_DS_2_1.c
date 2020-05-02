#include <stdio.h>
#include <stdlib.h>

void sort(int arr[],int n)
{
	int i,j,temp;
    for( i=0; i<n; i=i+2 )
    {
    	for( j=0; j<(n-i); j=j+2 )
    	{
    		if( arr[j] < arr[j+2] )
		{
			temp = arr[j];
			arr[j] = arr[j+2];
			arr[j+2] = temp;	
		}	
	}
    }
    
    for( i=1; i<n; i=i+2 )
    {
    	for( j=1; j<(n-i); j=j+2 )
    	{
    		if( arr[j] > arr[j+2] )
		{
			temp = arr[j];
			arr[j] = arr[j+2];
			arr[j+2] = temp;	
		}	
	}
    }
}

void Display( int arr[], int n )
{
	int i;
	for( i=0; i<n; i++ )
		printf("%d ", arr[i] );
}

int main()
{
    	int arr[100], i, n=10;
    	for( i=0; i<n; i++ )
     		arr[i] = rand()%100;
    	printf("\n\t array before sorting:\n\t");
    	Display(arr,n);

    	printf("\n\t array after sorting: \n\n\t");
    	sort( arr,n );
    	Display( arr,n );
    	return 0;
}

