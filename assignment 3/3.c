#include<stdio.h>
#include<stdlib.h>
struct N
{
    int data;
    struct N *lc,*rc;
};
struct N *root=NULL;
struct N* delete(struct N*, int);
void inorder(struct N *root);
void postorder(struct N *root);
void preorder(struct N *root);
int height(struct N*);
struct N* max(struct N*);
struct N* min(struct N*);
struct N* insert(struct N*,int);
struct N* create(int);
void main()
{
    int c,val;
    char ch;
    do
    {
        printf("Press 1 to insert a struct N.\nPress 2 to delete a number from the BT.\nPress 3 to find the maximum number.\nPress 4 to find the minimum number.\nPress 5 for Inorder Traversal.\nPress 6 for Preorder Traversal.\nPress 7 for Postorder Traversal.\nEnter your choice: ");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            printf("Enter the value you wanaa insert: ");
            scanf("%d",&val);
            root=insert(root,val);
            break;
        case 2:
            printf("Enter the number you wanna delete: ");
            scanf("%d",&val);
            root=delete(root,val);
            break;
        case 3:
            printf("The maximum number present into the BT is: %d",max(root)->data);
            break;
        case 4:
            printf("The minimum number present into the BT is: %d",min(root)->data);
            break;
        case 5:
            inorder(root);
            break;
        case 6:
            preorder(root);
            break;
        case 7:
            postorder(root);
            break;
        default:
            printf("Wrong Input!!");
            break;
        }
        printf("Size of the Node is: %d \n",sizeof(struct N));
        printf("Address of the root is: %d\n",root);
        printf("Do you wanna continue? [y/n] ");
        scanf(" %c",&ch);
    } while (ch!='n');
}
struct N* delete(struct N *p, int key)
{
    struct N *q;
    if(!p) // the desired node is null(doesn't exist)
    return NULL;
    if(!p->lc && !p->rc) // both the child is null.
    {
        if(p->data!=key)
        {
            printf("%d doesn't present into the BST.\n",key);
            return NULL;
        }
        if(p==root) // root is not having any child.
            root=NULL; //reset
        free(p);
        return NULL;
    }
    if(key<p->data) //searching left
    p->lc=delete(p->lc,key);
    else if (key>p->data) //searching right
    p->rc=delete(p->rc,key);
    else //key element has found
    {
        if(!p->lc) // p doesn't have any left child.
        {
            q=p->rc;
            free(p);
            return q;
        }
        else if(!p->rc) // p doesn't have any right child.
        {
            q=p->lc;
            free(p);
            return q;
        }
        else
        {
            if (height(p->lc)>=height(p->rc)) // height of left subtree is greater or equal to right subtree. 
            {
                q=min(p->rc); // then i want to delete from the right subtree, as it is having lesser number of nodes, less time to execute.
                p->data=q->data;
                p->rc=delete(p->rc,q->data);
            }
            else
            {
                q=max(p->lc);
                p->data=q->data;
                p->lc=delete(p->lc,q->data);
            }
        }
    }
    return p;
}
int height(struct N *p)
{
    int x,y;
    if(!p)
    return -1;
    x=height(p->lc);
    y=height(p->rc);
    return x>=y?x+1:y+1;
}
struct N *max(struct N *p)
{
    if(!p)
    printf("There is no elements present into the BST.\n");
    while (p->rc)
    p=p->rc;
    return p;
}
struct N *min(struct N *p)
{
    if(!p)
    printf("There is no elements present into the BST.\n");
    while (p->lc)
    p=p->lc;
    return p;
}
struct N* insert(struct N* p, int key)   
{
    struct N *t=p,*r; // initially the root is null, need to assign some value.
    if(!t)
     return create(key);// root assigned.
    else // try to call search function and take the address of the desired leaf node from that.
    {
        while (t) // t is for traversing
        {
            r=t; // r is the tail pointer.
            if(key==t->data) // not possible
                return p;
            else
                t=(key<t->data)?t->lc:t->rc;
        } // r is the leaf struct N. t is null.
        if(key>r->data)
            r->rc=create(key);
        else
            r->lc=create(key);
    }
    return p;
}
struct N *create(int key)
{
    struct N *temp=(struct N*)malloc(sizeof(struct N));
    temp->data=key;
    temp->lc=temp->rc=NULL;
    return temp;
}
void inorder(struct N *p)
{
    if(p)
    {
        inorder(p->lc);
        printf("%d ",p->data);
        inorder(p->rc);
    }
} 
void preorder(struct N *p)
{
    if(p)
    {
        printf("%d ",p->data);
        preorder(p->lc);
        preorder(p->rc);
    }
}
void postorder(struct N *p)
{
    if(p)
    {
        postorder(p->lc);
        postorder(p->rc);
        printf("%d ",p->data);
    }
}