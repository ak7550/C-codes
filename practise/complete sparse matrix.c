#include<stdio.h>
#include<stdlib.h>
typedef struct element
{
    int r,c,v;
} Element;

typedef struct sparse 
{
    int row,col,nonzero;// nonzero counts the total number of nonzero elements.
    Element *e;
} Sparse;
void create(Sparse *s);
void display(Sparse *s);
void main()
{
    Sparse *s1,*s2,*s3;
    create(s1);
    display(s1);
    create(s2);
    display(s2);
    s3=add(s1,s2);
    display(s3);
}
Sparse* add(Sparse *s1, Sparse *s2)
{
    Sparse *sum;
    sum=(Sparse*)malloc(sizeof(Sparse));
    sum->e=(Element*)malloc((s1->nonzero+s2->nonzero)*sizeof(Element)); // that should be the maximum number of elements in sum's elements.
    if (s1->row!=s2->row||s1->col!=s2->col)
        return NULL; // addition of the matrix is not possible as row and column numbers are not same for the both the matrices.
    sum->row=s1->row;
    sum->col=s1->col;
    
    return sum;
}
void create(Sparse *s)
{
    int i,rw,cl,nz,m,n,p;
    printf("Enter the value of the row: ");
    scanf("%d",&rw);
    s->row=rw;
    printf("Enter the value of the col: ");
    scanf("%d",&cl); // we don't need to take the zero's once again, that's why we're creating the sparse matrix. At the time of display the complete matrix we'll show the zeroes.
    s->col=cl;
    printf("Enter the total number of non zero elements: ");
    scanf("%d",&nz);
    s->nonzero=nz;
    //pur dynamic array e should have the length of the number of nonzero elements, so that we can take all the inputs into it.    
    s->e=(Element*)malloc(s->nonzero*sizeof(Element));
    printf("Enter the row,column and the values into the sparse matrix onen by one: ");
    for (i = 0; i < s->nonzero; i++)
    {
        scanf("%d%d%d",&m,&n,&p);
        s->e[i].r=m;
        s->e[i].c=n;
        s->e[i].v=p;
    }
}
void display(Sparse *s)
{
    int i,j,k=0;
    for ( i = 0; i < s->row; i++)
    {
        for(j=0;j<s->col;j++)
        {
            if(i==s->e[k].r&&j==s->e[k].c)
                printf("%d ",s->e[k++].v);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
