#include<stdio.h>
#include<stdlib.h>
struct N
{
    int data;
    struct N *lc, *rc;
};
struct N *root=NULL;
void inorder(struct N *p)
{
    if(p)
    {
        inorder(p->lc);
        printf("%d ",p->data);
        inorder(p->rc);
    }
    printf("\n");
}
int leafcount(struct N *p)
{
    if(p) // p is having some address.
    {
        if(!p->lc && !p->rc)
            return 1;
        else
            return leafcount(p->lc)+leafcount(p->rc);
    }
    return 0; // when root is not having any child.
}
struct N *insert(struct N*,int);
struct N* create(int);
void main()
{
    int c,val;
    char ch;
    do
    {
        printf("Press 1 to insert a node.\nPress 2 to count the leafnodes\nPress 3 to display all the elements in sorted order.\nEnter your choice: ");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            printf("Enter the value you wanaa insert: ");
            scanf("%d",&val);
            root=insert(root,val);
            break;
        case 2:
            printf("%d Leaf Nodes present into the tree.\n",leafcount(root));
            break;
        case 3:
            inorder(root);
            break;
        default:
            printf("Wrong Input!!");
            break;
        }
        printf("Do you wanna continue? [y/n] ");
        scanf(" %c",&ch);
    } while (ch!='n');
}

struct N* insert(struct N* p, int key)
{
    struct N *t,*r;
    t=p;
    //initially t is null, need to assign some value.
    if(!t)
     return create(key);// root assigned.
    else
    {
        while (t) // t is for traversing
        {
            r=t; // r is the tail pointer.
            if(key==t->data) // not possible
                return p;
            else
                t=(key<t->data)?t->lc:t->rc;
        } // r is the leaf node. t is null.
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