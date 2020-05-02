#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data,height;
    struct node *lc,*rc;
}*root=NULL;
typedef struct node Node;
void inorder(struct node *root);
void postorder(struct node *root);
void preorder(struct node *root);
int heightp(Node*);
int bfactor(Node*);
Node* create(int);
Node* insert(Node*,int);
Node* lrotation(Node*);
Node* rrotation(Node*);
Node* lrrotation(Node*);
Node* rlrotation(Node*);
Node* rotate(Node*);
int mod(int x)
{
    return (x<0)?-x:x;
}
int main()
{
    int x;
    char y;
    printf("Just Inserting the elements into the tree. Checking if the AVL law has been broken or not. If it's broken then rotation will be applied.\n");
    do
    {
        printf("Enter the value of the new node: ");
        scanf("%d",&x);
        root=insert(root,x);
        printf("Do you wanna insert a new node: ");
        scanf(" %c",&y);
    } while (y!='n');
    printf("Result of Inorder traversal: ");
    inorder(root);
    printf("Result of Preorder traversal: ");
    preorder(root);
}
Node* insert(Node *p,int key)
{
    char y;
    if(!p)
    return create(key);
    else if(p->data > key)
    p->lc=insert(p->lc,key);
    else
    p->rc=insert(p->rc,key);
   // p->height=heightp(p);//final addition of the height of all the nodes.
    while(mod(bfactor(p))>=2 || y!='n')
    {
        printf("%d node is imbalanced!!\nWould you like to rotate? [y/n]",p->data);
        scanf(" %c",&y);
        if(y!='n')
            p=rotate(p);
    }
    return p;
}
Node* rlrotation(Node *p)
{
    Node *prl=p->rc->lc;
    p->rc->lc=prl->rc;
    prl->rc=p->rc;
    p->rc=prl->lc;
    prl->lc=p;
    p->height=heightp(p);
    prl->height=heightp(prl);
    if(root==p)
        root=prl;
    return prl;
}
Node* lrrotation(Node *p)
{
    Node *plr=p->lc->rc;
    p->lc->rc=plr->lc;
    plr->lc=p->lc;
    p->lc=plr->rc;
    plr->rc=p;
    p->height=heightp(p);
    plr->height=heightp(plr);
    if(root==p)
        root=plr;
    return plr;
}
Node* lrotation(Node *p)
{
    Node *pr=p->rc, *prl=pr->lc;
    pr->lc=p;
    p->lc=prl;
    p->height=heightp(p);
    pr->height=heightp(pr);
    if(root==p)
        root=pr;
    return pr;
}
Node* rrotation(Node *p)
{
    Node *pl=p->lc, *plr=pl->rc;
    pl->rc=p;
    p->rc=plr;
    p->height=heightp(p);
    pl->height=heightp(pl);
    if(root==p)
        root=pl;
    return pl;
}
Node* rotate(Node *p)
{
    // 4 types of rotation.
    return (bfactor(p)>=2)?(bfactor(p->lc)>0?rrotation(p):lrrotation(p)):(bfactor(p->rc)>0?lrotation(p):rlrotation(p));
}
int bfactor(Node *p)//calculates balance factor of a certain node.
{
    return heightp(p->lc)-heightp(p->rc); // negative signifies that the left child is having less height or nodes.
}
int heightp(Node *p)
{
    int x,y;
    if(!p)
    return -1;
    x=heightp(p->lc);
    y=heightp(p->rc);
    return x>=y?x+1:y+1;
}
Node* create(int key)
{
    Node *t=(Node*)malloc(sizeof(Node));
    t->data=key;
    t->lc=t->rc=NULL;
    t->height=0;//height of a leaf node is initially 0;
    return t;
}
void inorder(struct node *p)
{
    if(p)
    {
        inorder(p->lc);
        printf("%d ",p->data);
        inorder(p->rc);
    }
} 
void preorder(struct node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        preorder(p->lc);
        preorder(p->rc);
    }
}
void postorder(struct node *p)
{
    if(p)
    {
        postorder(p->lc);
        postorder(p->rc);
        printf("%d ",p->data);
    }
}