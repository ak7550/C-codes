#include<stdio.h>
void main()
{
    int arr[100],n,i;
    printf("How many numbers are present into the array: ");
    scanf("%d",&n);
    printf("Enter the numbers one by one: \n");
    for(i=0;i<n;i++)
    scanf("%d",(arr+i));
    printf("Numbers present into the array are: \n");
    for(i=0;i<n;i++)
    printf("Address of %d is: %d\n",*(arr+i),arr+i);

}