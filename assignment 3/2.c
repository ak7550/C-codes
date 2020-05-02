#include<stdio.h>
#include<stdlib.h>
struct N{
    int data;
    struct N *lc,*rc;
}*root=NULL;
struct Q
{
    struct N *node; // node is gonna store the address of the binary tree node.
    struct Q *next;
};
typedef struct N NODE;
typedef struct Q QUEUE;
QUEUE *front=NULL,*rear=NULL;
QUEUE *createq(NODE *t)
{
    QUEUE *temp=(QUEUE*)malloc(sizeof(QUEUE));
    temp->node=t;
    temp->next=NULL;
    return temp;
}
void enq(NODE *t)
{
    if(!front) //it means front is not been initialised yet. Initialise it first.
        rear=front=createq(t);
    else
    {
        rear->next=createq(t);
        rear=rear->next; // rear is always pointing to the last node.
    }
}
NODE *deq()
{
    NODE *temp;
    QUEUE *t;
    if (front==rear) // there's only one single node is present into 
    {
        temp=rear->node;
        free(rear); // resetting the linked list.
        rear=front=NULL;    
    }
    else
    {
        t=front;
        front=front->next;
        temp=t->node;
        free(t);
    }
    return temp;
}
NODE *create(int x)
{
    NODE *temp=(NODE*)malloc(sizeof(NODE));
    temp->data=x;
    temp->lc=temp->rc=NULL;
    return temp;
}
void generate()
{
    NODE *p;
    int x;
    char ch;
    printf("Enter the root values: ");
    scanf("%d",&x);
    enq(root=create(x)); // enqueues the address of the node into the queue.
    while (front)
    {
        p=deq(); // returns the address of the node.
        printf("Do you wanna add left child of %d? [y/n]",p->data);
        scanf(" %c",&ch);
        if(ch=='y'||ch=='Y')
        {
            printf("Enter the value for the left child of %d: ",p->data);
            scanf("%d",&x);
            enq(p->lc=create(x));
        }
        printf("Do you wanna add right child of %d? [y/n]",p->data);
        scanf(" %c",&ch);
        if(ch=='y'||ch=='Y')
        {
            printf("Enter the value for the right child of %d: ",p->data);
            scanf("%d",&x);
            enq(p->rc=create(x));
        }
    }
}
void inorder(NODE *root);
void postorder(NODE *root);
void preorder(NODE *root);
void main()
{
    int ch,data;
    char c;
    do
    {
        printf("Press 1 to generate a BT.\n Press 2 for Inorder traversal.\nPress 3 for Preorder Traversal.\nPress 4 for Postorder Traversal.\nEnter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            generate();
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        default:
            break;
        }
        printf("Do you wanna continue? [y/n]");
        scanf(" %c",&c);
    } while (c!='n');
}
void inorder(NODE *p)
{
    if(p)
    {
        inorder(p->lc);
        printf("%d ",p->data);
        inorder(p->rc);
    }
}
void preorder(NODE *p)
{
    if(p)
    {
        printf("%d ",p->data);
        preorder(p->lc);
        preorder(p->rc);
    }
}
void postorder(NODE *p)
{
    if(p)
    {
        postorder(p->lc);
        postorder(p->rc);
        printf("%d ",p->data);
    }
}