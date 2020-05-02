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
int* isort(int a[],int s)
{
    int i,j,x;
    for(i=1;i<s;i++)
    {
        x=a[i];
        j=i-1;
        while (j>=0&&a[j]>x)
        {
            a[j+1]=a[j];
            j=j-1; // shifting the index to create the free space to insert x.
        }
        a[j+1]=x; //inserting x to the appropriate position.
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
    printf("Before Insertion sort the array is: \n");
    display(arr,size);
    arr=isort(arr,size);
    printf("After Insertion sort the array is: \n");
    display(arr,size);
}