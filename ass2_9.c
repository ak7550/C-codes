#include<stdio.h>
#include<stdlib.h>
struct N{
    int data;
    struct N *next;
};
struct N *head=NULL,*head2=NULL;
struct N *insert(struct N*,int); // we're providing the position in which the node is gonna entered.
struct N *delete(struct N*,int); // we're providing the position in which the node will be deleted.
void display(struct N*);
struct N *split(struct N *head);
struct N* create();
int count(struct N *head) // provides the information regarding the total number of the nodes present into the linked list.
{
    int n=0;
    struct N *temp;
    temp=head;
    if(head)
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
        printf("Press 1 to insert a new node at a specified position.\nPress 2 to delete a node from specified position.\nPress 3 to count the number of the nodes of the linked list.\nPress 4 to display the nodes of the linked list.\nEnter 5 to split the linked list.\nEnter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter the position of wanna add a new node: ");
            scanf("%d",&pos);
            head=insert(head,pos);
            break;
        case 2:
            printf("Enter the position of wanna delete a node: ");
            scanf("%d",&pos);
            head=delete(head,pos);
            break;
        case 3:
            printf("The total nodes present into the linked list are: %d\n",count(head));
            break;
        case 4:
            display(head);
            break;
        case 5:
            head=split(head);
            break;
        default:
            printf("\nWrong Input!!");
            break;
        }
        printf("Do you wanna continue?[y/n] ");
        scanf(" %c",&c);
    } while (c!='n');
}
struct N *split(struct N *head)
{
    int i,n=count(head); // n is having the total number of nodes present into the main linked list.
    struct N *temp;
    temp=head;
    for(i=1;i<n/2;i++) // basic traversing.
        temp=temp->next;
    head2=temp->next;
    temp->next=NULL;
    printf("Two linked list head and head2 have been generated.\n");
    printf("The number of nodes present into the first linked list is: %d",count(head));
    printf("\nThe number of nodes present into the second linked list is: %d",count(head2));
    printf("First linked list is: \n");
    display(head);
    printf("Second linked list is: \n");
    display(head2);
    return head;
}
struct N *delete(struct N *head,int pos)
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
        }
    }
    else if (pos>count(head))
    printf("Deleting from %d position is not possible.\nCurrently we are only having %d nodes in the linked list.\n",pos,count(head));
    else
    {
        for (i=2;i<pos;i++) // basic traversing
        temp=temp->next;
        t2=temp->next;
        temp->next=temp->next->next;
        free(t2);
    }
    return head;
}
struct N *insert(struct N* head,int pos)
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
    }
    else if(pos>count(head)+1) // we can hardly insert at n+1th position.
    printf("Insertion at %d is not possible. We Only have %d nodes currently present into the linked list.\n",pos,count(head));
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
    }
    return head;
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
void display(struct N *head)
{
    struct N *temp;
    if (!head)
        printf("\nThe Linked list is empty. Nothing is to show.\n");
    else
    {
        printf("The linked list is: \n");
        temp = head;
        while (temp->next)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}
