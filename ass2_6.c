#include<stdio.h>
#include<stdlib.h>
struct N{
    int data;
    struct N *next,*pre;
};
struct N *head;
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
        printf("Press 1 to insert a new node at a specified position.\nPress 2 to delete a node from specified position.\nPress 3 to count the number of the nodes of the linked list.\nPress 4 to reverse the nodes of the linked list.\nPress 5 to display the nodes of the linked list.\nEnter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter the position of wanna add a new node: ");
            scanf("%d",&pos);
            insert(pos);
            break;
        case 2:
            printf("Enter the position of wanna delete a node: ");
            scanf("%d",&pos);
            delete(pos);
            break;
        case 3:
            printf("The total nodes present into the linked list are: %d\n",count());
            break;
        case 4:
            reverse(); //not done yet.
            break;
        case 5:
            display();
            break;
        default:
            printf("\nWrong Input!!");
            break;
        }
        printf("Do you wanna continue?[y/n] ");
        scanf(" %c",&c);
    } while (c!='n');
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
    temp->next=temp->pre=NULL;
    return temp;
}
void insert(int pos)
{
    struct N *temp,*node,*temp2;
    int i=1;
    temp=head;
    if(pos==1||pos==0) //insertion at head
    {
        if(!head)//head is empty.
        head=create();
        else //head is having some node.
        {
            node=create();
            node->next=head;
            head->pre=node;
            head=node;
        }
        no++;
    }
    else if(pos>no+1) // we can hardly insert at n+1th position.
    printf("Insertion at %d is not possible. We Only have %d nodes currently present into the linked list.\n",pos,no);
    else
    {
        while(i<pos)// traversing to my desired node.
        { 
          temp2=temp;
          temp=temp->next;
          i++;
        }
        node=create();
        temp2->next=node;
        node->pre=temp2;
        node->next=temp;
        if(temp) // temp is not null.
            temp->pre=node;
        no++;   
    }
}
void delete(int pos)
{
    struct N *temp,*t2;
    int i=2;
    temp=head;
    if(pos==1||pos==0)
    {
        if(!head)
        printf("The linked list is empty.\n Nothing is to delete.\n");
        else
        {
            head=head->next;
            free(temp);
            head->pre=NULL;
            no--;
        }
    }
    else if (pos>no)
    printf("Deleting from %d position is not possible.\nCurrently we are only having %d nodes in the linked list.\n",pos,no);
    else
    {
        for(i=2;i<pos;i++) // basic traversing just before the desired node.
            temp=temp->next;
        t2=temp->next;
        if(temp->next->next) // temp is not the previous node of the last node.
        temp->next->next->pre=temp;
        temp->next=temp->next->next;
        free(t2);
        no--;
    }
}
void reverse()
{
    struct N *n,*p=NULL,*temp;
    temp=head;
    while (temp) 
    {
        n=temp->next;
        p=temp->pre;
        temp->next=p;
        temp->pre=n;
        temp=temp->pre;
    } // p won't have any address if it doesn't enter into the loop.
    if(p) // if p is having some address.
    head=p->pre;    
}