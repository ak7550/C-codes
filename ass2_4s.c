#include<stdio.h>
#include<stdlib.h>
struct N{
    int data;
    struct N *next;
};
int no=0;// to count the total number of the nodes present into the linked list.
struct N *head=NULL,*top=NULL;
void push();
void pop();
void display();
struct N* create();
int count()
{
    int n;
    struct N *temp;
    if(!head)
        return 0;
    temp=head;
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
        printf("Press 1 to push.\nPress 2 to pop.\nPress 3 to display the nodes of the linked list.\nPress 4 to count the items of the linked list.\nEnter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
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
    if(!head)
        printf("The Stack is empty. Nothing is to show.\n");
    else
    {
        printf("The items into the stack are: \n");
        temp=head;
        while (temp->next)
         {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d \n",temp->data);
    }
}
void push()
{
    if(!head) //it means head is not been initialised yet. Initialise it first.
        top=head=create();
    else
    {
        top->next=create();
        top=top->next; // top is always pointing to the last node.
    }
    no++;
}
void pop()
{
    struct N *t2;
    if(!head)
    {
        printf("The Stack is empty. Nothing is to pop.\n");
        return;
    }
    else if (head==top) // there's only one single node is present into 
    {
        free(top); // resetting the linked list.
        top=head=NULL;    
        no=0;
    }
    else
    {
        for(t2=head;t2->next!=top;t2=t2->next);//traversing till the previous node of the last node.
        t2->next=NULL;
        free(top);
        top=t2;
        no--;
    }
}