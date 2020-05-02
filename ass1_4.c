#include<stdio.h>
#include<time.h>
#include<stdlib.h>
struct N
{
    int data;
    struct N *next;
};
struct N *head=NULL;
int no; // no is gonna count the total number of the nodes.
void insert();
void display();
struct N* create();
struct N* traverse(struct N*,int);
void main()
{
    int ch;
    char c;
    srand(time(0));
    // To create the linked list of 10 nodes.
    for(ch=0;ch<10;ch++)
        insert();
    do
    {
        printf("Press 1 to insert at the end.\nPress 2 to diaplay all the nodes.\nEnter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        default:
            printf("Wrong Input!!.\n");
            break;
        }
        printf("Do you wanna continue?[y/n]: ");
        scanf(" %c",&c);
    } while (c!='n');
}
void insert()
{
    struct N *temp;
    if(!head)
        head=create();
    else
    {
        temp=traverse(head,0); // 0 represents it won't print anything during the traverse.
        temp->next=create();
    }
    no++; // as a new node is being connected with the linked list, we're just adding 1 with the no value.
}

void display()
{
    struct N *temp;
    if(!head)
        printf("The Linked list is empty. Nothing is to show.\n");
    else
    {
        printf("The linked list are: \n");
        temp=traverse(head,1);
    }
    printf("%d \n",temp->data);
}
struct N* traverse(struct N* temp, int f)
{
    while (temp->next)
    {
        if(f)
            printf("%d ",temp->data);
        temp=temp->next;
    }
    return temp;
}
struct N* create()
{
    struct N *temp;
    int x;
    temp=(struct N*)malloc(sizeof(struct N));
    /*printf("Enter the data present into the node: ");
    scanf("%d",&x); // this gives you the ability to take user input and connect it with the node.
    temp->data=x;*/
    temp->data=rand();
    temp->next=NULL;
    return temp;
}