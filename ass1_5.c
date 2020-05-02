#include<stdio.h>
#include<stdlib.h>
struct N{
    int data;
    struct N *next;
};
struct N *head=NULL;
int no=0; // no is gonna count the total number of the nodes.
void insert(int); // we're providing the position inwhich the node is gonna entered.
void display();
struct N* create();
void delete(int);
void reverse();
int count()
{
    int n;
    struct N *temp;
    temp=head;
    if(!head)
        return 0;
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
        printf("Press 1 to Insert a new node at the begining.\nPress 2 to insert a new node at the end.\nPress 3 to insert a new node at a specified position.\nPress 4 to delete a node from specified position.\nPress 5 to count the number of the nodes of the linked list.\nPress 6 to display the nodes of the linked list.\nEnter 7 to reverse the nodes.\nEnter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            insert(1);
            break;
        case 2: 
            insert(no+1);
            break;
        case 3:
            printf("Enter the position of wanna add a new node: ");
            scanf("%d",&pos);
            insert(pos);
            break;
        case 4:
            printf("Enter the position of wanna delete a node: ");
            scanf("%d",&pos);
            delete(pos);
            break;
        case 5:
            printf("The total nodes present into the linked list are: %d\n",count());
            break;
        case 6:
            display();
            break;
        case 7:
            reverse();
            break;
        default:
            printf("\nWrong Input!!");
            break;
        }
        printf("Do you wanna continue?[y/n] ");
        scanf(" %c",&c);
    } while (c!='n');
}
void insert(int pos)
{
    struct N *temp,*node,*temp2;
    int i=1;
    temp=head;
    if(pos==1||pos==0) //insertion at head
    {
        if(!head)
        head=create();
        else
        {
            node=create();
            node->next=head;
            head=node;
        }
        no++;
    }
    else if(pos>no+1) // we can hardly insert at n+1th position.
    printf("Insertion at %d is not possible. We Only have %d nodes currently present into the linked list.\n",pos,no);
    else
    {
        while(i<pos) // traversing to my desired node.
        { 
          temp2=temp;
          temp=temp->next;
          i++;
        } 
        node=create();
        temp2->next=node;    
        node->next=temp;
        no++;   
    }
}
void delete(int pos)
{
    struct N *temp,*t2;
    int i=1;
    temp=head;
    if(pos==1||pos==0)
    {
        if(!head)
        printf("The linked list is empty.\n Nothing is to delete.\n");
        else
        {
            head=head->next;
            free(temp);
            no--;
        }
    }
    else if (pos>no)
    printf("Deleting from %d position is not possible.\nCurrently we are only having %d nodes in the linked list.\n",pos,no);
    else
    {
        for (i=2;i<pos;i++) // basic traversing
        temp=temp->next;
        t2=temp->next;
        temp->next=temp->next->next;
        free(t2);
        no--;
    }
}
void display()
{
    struct N *temp;
    if(!head)
        printf("The Linked list is empty. Nothing is to show.\n");
    else
    {
        printf("The linked list are: \n");
        temp=head;
        while (temp->next)
         {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d \n",temp->data);
    }
}
struct N* create()
{
    struct N *temp;
    int x;
    temp=(struct N*)malloc(sizeof(struct N));
    printf("Enter the data present into the node: ");
    scanf("%d",&x); // this gives you the ability to take user input and connect it with the node.
    temp->data=x;
 // temp->data=rand(); // I hve to enter the new values of the nodes, so any option to use rand function.
    temp->next=NULL;
    return temp;
}
void reverse()
{
    struct N *front=NULL, *rear=NULL,*temp;
    temp=head;
    while(temp)
    {
        front=temp->next;
        temp->next=rear;
        rear=temp;
        temp=front;
    }
    head=rear;
}