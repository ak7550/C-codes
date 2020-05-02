#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void main()
{
    int arr[16],i;
    srand(time(0));
    printf("Taking the 15 elements one by one randomly.\n ");
    // Taking random 15 inputs.
    for(i=0;i<15;i++)
    arr[i]=rand();
    printf("The New Array is: \n");
    for(i=0;i<15;i++)
    printf("%d ",arr[i]);
    // Entering a new element after 6th data means entering the data at 6th index;
    for(i=14;i>=6;i--)
    arr[i+1]=arr[i];
    printf("\nEnter the new data: ");
    scanf("%d", (arr+i+1));
    printf("The New Modified Array is: \n");
    for(i=0;i<15;i++)
    printf("%d ",arr[i]);
    // To delete the data after 6th position. We just need to shift the elements in reverse order.
    for(i=6;i<15;i++)
    arr[i]=arr[i+1];
    // Now to print the new array.
    printf("\nThe New Modified Array is: \n");
    for(i=0;i<15;i++)
    printf("%d ",arr[i]);
}