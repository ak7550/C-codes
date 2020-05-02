#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void display(int *a, int n)
{
    int i;
    printf("\n");
    for ( i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("\n");
}
void main()
{
    int size,*arr,i;
    srand(time(0));
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    arr=(int*)malloc(sizeof(int)*size);
    for ( i = 0; i < size; i++)
        arr[i]=rand()%500;
    printf("Before sorting the array is: ");
    display(arr,size);
    qsort(arr,size);
    printf("After sorting the array is: ");
    display(arr,size);
}