#include<stdio.h>
#include<stdlib.h>
struct N{
    int data;
    struct N *next;
};
int no=0;// to count the total number of the nodes present into the linked list.
struct N *front=NULL,*rear=NULL;
void display(); //done
struct N* create(); //done
void enqueue();
void dequeue();
int count() //done
{
    int n;
    struct N *temp;
    if(!front)
        return 0;
    temp=front;
    for(n=1;temp->next;n++)
        temp=temp->next;
    return n;
}
void main()
{
    int ch,pos;
    char c;
    do
    {
        printf("Press 1 to insert an iten in the queue.\nPress 2 to delete an item from the queue.\nPress 4 to count the number of the items present into the queue.\nPress 3 to display all the items in the queue.\nEnter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2: 
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("The total nodes present into the linked list are: %d\n",count());
            break;
        default:
            printf("\nWrong Input!!");
            break;
        }
        printf("Do you wanna continue?[y/n] ");
        scanf(" %c",&c);
    } while (c!='n');
}
struct N* create()
{
    struct N *temp;
    int x;
    temp=(struct N*)malloc(sizeof(struct N));
    printf("Enter the data present into the node: ");
    scanf("%d",&x); // this gives you the ability to take user input and connect it with the node.
    temp->data=x;
    temp->next=NULL;
    return temp;
}
void display()
{
    struct N *temp;
    if(!front)
        printf("The Queue is empty. Nothing is to show.\n");
    else
    {
        printf("The items into the Queue are: \n");
        temp=front;
        while (temp->next)
         {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d \n",temp->data);
    }
}
void enqueue()
{
    if(!front) //it means front is not been initialised yet. Initialise it first.
        rear=front=create();
    else
    {
        rear->next=create();
        rear=rear->next; // rear is always pointing to the last node.
    }
    no++;
}
void dequeue()
{
    struct N *t;
    if(!front)
        printf("The Queue is empty.\n Nothing is to dequeue.\n");
    else if (front==rear) // there's only one single node is present into 
    {
        free(rear); // resetting the linked list.
        rear=front=NULL;    
        no=0;
    }
    else
    {
        t=front;
        front=front->next;
        free(t);
        no--;
    }
}