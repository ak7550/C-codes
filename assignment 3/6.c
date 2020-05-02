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
void merge(int a[], int low, int mid, int high);
void msort(int a[],int low, int high)
{
    int middle=(low+high)/2;
    //Deviding the array into two equal parts.
    msort(a,low,middle);
    msort(a,middle+1,high);
    merge(a,low,middle,high);
}
void merge(int a[], int low, int mid, int high)
{
    int i,j=0,n1=mid-low+1,n2=high-mid;
    int *la=(int*)malloc(sizeof(int)*n1),*ra=(int*)malloc(sizeof(int)*n2);
    //inserting the data into la and ra
    for(i=0;i<n1;i++)
        la[i]=a[low+i];
    for ( i = 0; i < n2; i++)
        ra[i]=a[mid+1+j];
    //finally inserting to the main array with proper comparison.
    i=0;
    while (i<n1 && j<n2)
        a[low++]=(la[i]<=ra[j])?la[i++]:ra[j++];
    while(i<n1)
        a[low++]=la[i++];
    while(j<n2)
        a[low++]=ra[j++];
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
    printf("Before Merge sort the array is: \n");
    display(arr,size);
    msort(arr,0,size-1); // every time, we are starting with the address of head, so we don't need to return.
    printf("After Merge sort the array is: \n");
    display(arr,size);
}