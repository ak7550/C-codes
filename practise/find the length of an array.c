#include<stdio.h>
void length(int a[])
{
    printf("\nLength fo the array is: %d",sizeof(a)/sizeof(a[0]));
}
void main()
{
    int a[]={2,3,5,6,66,65,54,12};
    printf("Length fo the array is: %d",sizeof(a)/sizeof(a[0]));
    length(a);
}