#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void display(int a[], int s)
{
    int i=0;
    while (i<s)
        printf(" %d ",a[i++]);
    printf("\n");
}
int* bsort(int a[],int s)
{
    int i,j;
    for (i=0; i < s; i++)
    {
        for (j = 1; j < s-i; j++)
        {
            if (a[j-1]>a[j])
            {
                int k=a[j-1];
                a[j-1]=a[j];
                a[j]=k;
            }
        }
    }
    return a;
}
void main()
{
    int *arr, size,i;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    arr=(int*)malloc(sizeof(int)*size);
    srand(time(0));
    //array initialization.
    for ( i = 0; i < size; i++)
        arr[i]=rand()%100;
    printf("Before Bubble sort the array is: \n");
    display(arr,size);
    arr=bsort(arr,size);
    printf("After bubble sort the array is: \n");
    display(arr,size);
}