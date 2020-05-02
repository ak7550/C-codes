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
int* ssort(int a[],int s)
{
    int i,j,min;
    for(i=0;i<s;i++)
    {
        min=i;
        for(j=i+1;j<s;j++)
            if(a[j]<a[min])
                min=j;
        int k=a[min];
        a[min]=a[i];
        a[i]=k;
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
    printf("Before Selection sort the array is: \n");
    display(arr,size);
    arr=ssort(arr,size);
    printf("After Selection sort the array is: \n");
    display(arr,size);
}