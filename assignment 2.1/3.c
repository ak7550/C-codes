#include<stdio.h>
#include<stdlib.h>
int size=100, top=-1,f=1;
char st[100],arr[100];
void push(char c)
{
    st[++top]=c;
}
char pop()
{
    return st[top--];
}
void main()
{
    int i;
    printf("Enter the array of parenthesis: ");
    scanf("%s",arr);
    for(i=0;arr[i]!='\0';i++)
    {
        if(arr[i]=='(')
            push(arr[i]);
        else
        { //((( )) (( ))) 
            if(pop()!=')')
                {
                    printf("Not Well Formed.\n");
                    f=0;
                    break;
                }
        }
    }
    if(f)
    printf("Well Formed.\n");
}