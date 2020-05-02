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
void ssort(int *a, int n)
{
    int i,j,k,min;
    for ( i = 0; i < n-1; i++)
    {
        for (j = min=i; j < n; j++)
            if (a[min]>a[j])
                min=j;
        k=a[min];
        a[min]=a[i]; //swapping a[min] & a[i]
        a[i]=k;
        display(a,n);// just to check each pass
    }
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
    ssort(arr,size);
    printf("After sorting the array is: ");
    display(arr,size);
}