#include<stdio.h>
#include<stdlib.h>
int no=0,front=0,rear=0,*arr,l;
void enqueue();
void dequeue();
void display();
int fullq();
int empq();
void count()
{
    printf("There is %d no of items present into the queue.\n",no);
}
void construct(int l) //donne
{
    free(arr); // let the previous queue get free.
    front=no=0;//resetting every single element.
    rear=-1;
    arr=(int*)malloc(l*sizeof(int));// an array has been made dunamically.
    printf("A completely new queue of length %d has been made.\nENJOY!!\n",l);
}
void main()
{
    int ch;
    char c;
    l=4;
    construct(l); // initially a queue of length 3 has been made.
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
void display() //some changes are needed.
{
    int i=front;
    if(empq())
        printf("The Queue is empty.\nNo items to display.\n");
    else
    {
        printf("The items present into the queue are: \n");
        do
        {
            printf("%d ",arr[i]);
            i=(i+1)%l;
        }while(i!=rear);
        printf("%d\n",arr[i]);
    }
}
int fullq()
{
    if(rear==l-1 && front==0 || front-1==rear && rear>=0)
    return 1;
    return 0;
}
int empq()
{
    if(rear==-1 && front==0)
        return 1;
    return 0;
}
void enqueue()
{
    int x;
    if(fullq())
        printf("The Queue is full. Insertion of a new number is not possible.\n");
    else
    {
        printf("Enter the new number to insert: ");
        scanf("%d",&x);
        rear=(rear+1)%l;
        arr[rear]=x;
        printf("\nInserted!!\n");
        no++;
    }
}
void dequeue()
{
    if(empq())
        printf("The Queue is empty.\nNot possible to delete anything.\n");
    else
    {
        printf("%d is dequeued.\n",arr[front]);
        if(front==rear)
        construct(l);
        else
        {
            front=(front+1)%l; // front is always pointing to the first node.
            no--;
        }   
    }
}