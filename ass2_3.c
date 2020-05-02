#include<stdlib.h>
#include<stdio.h>
int *arr, rear=0,front=0,l;
void construct(int l)
{
    free(arr); // let the previous queue get free.
    rear=front=0;
    arr=(int*)malloc(l*sizeof(int));// a queue has been made.
    printf("A completely new queue of length %d has been made.\nENJOY!!\n",l);
}
void enqueue();
void dequeue();
void display();
int fullq();
int empq();
void count()
{
    if(empq())
        printf("The Queue is empty.\nThere's no items present.\n");
    else
        printf("There is %d no of items present into the queue.\n",rear-front);
}
void main()
{
    int ch;
    char c;
    construct(10); // initially a queue of length 10 has been made.
    do
    {
        printf("Press 1 to construct a new queue.\nPress 2 to insert an iten in the queue.\nPress 3 to delete an item from the queue.\nPress 4 to count the number of the items present into the queue.\nPress 5 to display all the items in the queue.\nEnter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter the length of the new Queue: ");
            scanf("%d",&l);
            construct(l);
            break;
        case 2:
            enqueue();
            break;
        case 3: 
            dequeue();
            break;
        case 4:
            count();
            break;
        case 5:
            display();
            break;
        default:
            printf("Wrong Input!!\n");
            break;
        }
        printf("Do you wanna continue?[y/n]");
        scanf(" %c",&c);
    } while (c!='n');
}
void enqueue()
{
    if(fullq())
        printf("The Queue is full. Insertion of a new number is not possible.\n");
    else
    {
        printf("Enter the new number to insert: ");
        scanf("%d",arr+(rear++));
        printf("\nInserted!!\n");
    }
}
void dequeue()
{
    if(empq())
        printf("The Queue is empty.\nNot possible to delete anything.\n");
    else
        printf("%d has been dequeud.\n",arr[front++]);
}
void display()
{
    int i;
    if(empq())
        printf("The Queue is empty.\nNo items to display.\n");
    else
    {
        printf("The items present into the queue are: \n");
        for(i=front;i<rear;i++)
            printf("%d ",arr[i]);
        printf("\n");
    }
}
int empq()
{
    if(front==rear)
        return 1;
    return 0;
}
int fullq()
{
    if(rear==l)
        return 1;
    return 0;
}