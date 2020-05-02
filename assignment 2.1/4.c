#include<stdio.h>
#include<stdlib.h>
int* sort(int *arr, int size)
{
    int i,j,temp;
    for (i=0;i<size;i++)
    {
        for (j=1;j<size-i;j++)
        {
            if(arr[j-1]>arr[j])
            {
                temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
    return arr;
}
int *reverse(int *arr, int size)
{
    int *a=(int*)malloc(size*sizeof(int)),i;
    for (i=0;i<size;i++)
        a[i]=arr[size-i-1];
    return a;
}
void display(int *arr, int size)
{
    int i;
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
}
void main()
{
    int size,*even,*odd,i;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    even=(int*)malloc(sizeof(int)*(size%2)?(size/2)+1:(size/2));
    odd=(int*)malloc(sizeof(int)*size/2);
    printf("Enter the values present into the array one by one: \n");
    for (i=0;i<size;i++)
    {
        if (i%2)
            scanf("%d",odd+(i/2));
        else
            scanf("%d",even+(i/2));
    }
    printf("Unsorted odd array is: \n");
    display(odd,size/2);
    odd=sort(odd,size/2);
    printf("\nSorted odd array is: \n");
    display(odd,size/2);
    printf("\nUnsorted even array is: \n");
    display(even,(size%2)?(size/2)+1:(size/2));
    even=sort(even,(size%2)?(size/2)+1:(size/2));  
    printf("\nSorted even array is: \n");
    display(even,(size%2)?(size/2)+1:(size/2));
    even=reverse(even,(size%2)?(size/2)+1:(size/2)); 
    printf("\nReversed even array is: \n");
    display(even,(size%2)?(size/2)+1:(size/2));
    printf("\nThe sorted array is: \n");
    for (i=0;i<size;i++)
    {
        if (i%2)
            printf("%d ",odd[i/2]);
        else
            printf("%d ",even[i/2]);
    }
}