#include<stdio.h>
#include<string.h>
void add();
void display();
void search();
void modify();
int search_roll();
int search_name();
int search_in();
struct st
{
    int roll;
    char name[40];
    float percentage;
};
struct st stu[100]; // variable array declared globally.
int top=-1; // top counts the index of the last entry.
void main()
{
    int ch;
    char c;
    do
    {
        printf("Press 1 to add a new record.\nPress 2 dislpay all the existing record.\nPress 3 to search record of any condition.\nPress 4 to modify a record.\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            add();
            break;
            case 2:
            display();
            break;
            case 3:
            search();
            break;
            case 4:
            modify();
            break;
            default:
            printf("You have entered a wrong input.\n");
            break;
        }
        printf("Do you wanna continue: [y/n] ");
        scanf(" %c",&c);
        /* code */
    } while (c!='n');
}
void add()
{
    top++;
    printf("Enter the roll no of the student: ");
    scanf("%d",&stu[top].roll);
    printf("Enter the name of the student: ");
    scanf("%s",stu[top].name);
    printf("Enter the percentage of marks of %s: ",stu[top].name);
    scanf("%f",&stu[top].percentage);
}
void display()
{
    int i;
    if(top==-1)
    printf("No information about the students.\n");
    else
    {
        printf("Records are: \n");
        for(i=0;i<=top;i++)
            printf("Roll no. %d\nName: %s\nPercentage: %f\n\n",stu[i].roll,stu[i].name,stu[i].percentage);
    }
}
void search()
{
    int ch,in=-1;//if in remain -1. that means there's no record with given information.
    printf("Press 1 to search by index.\nPress 2 to search by roll.\n Press 3 to search by Name.\nEnter your choice: ");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        in=search_in();
        break;
    case 2:
        in=search_roll();
        break;
    case 3:
        in=search_name();
        break;
    default:
        printf("Wrong Input!!");
        break;
    }
    if(in==-1)
        printf("There's no record having your provided information.\n");
    else
        printf("Roll no. %d\nName: %s\nPercentage: %f\n\n",stu[in].roll,stu[in].name,stu[in].percentage);
}
void modify()
{
    int ch,in=-1;//if in remain -1. that means there's no record with given information.
    printf("Press 1 to modify by index.\nPress 2 to modify by roll.\n Press 3 to modify by Name.\nEnter your choice: ");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        in=search_in();
        break;
    case 2:
        in=search_roll();
        break;
    case 3:
        in=search_name();
        break;
    default:
        printf("Wrong Input!!");
        break;
    }
    if(in==-1)
        printf("There's no record having your provided information.\n");
    else
    {
    printf("Enter the roll no of the student: ");
    scanf("%d",&stu[in].roll);
    printf("Enter the name of the student: ");
    scanf("%s",stu[in].name);
    printf("Enter the percentage of marks of %s: ",stu[in].name);
    scanf("%f",&stu[in].percentage);
    }
}
int search_in()
{
    int in=-1,ind;
    printf("Enter the index you wanna search for: ");
    scanf("%d",&ind);
    if(ind<=top)
    in=ind;
    return in;
}
int search_name()
{
    int i,in=-1;
    char name[30];
    printf("Enter the name of the student: ");
    scanf("%s",name);
    for(i=0;i<=top;i++)
    {
        if(strcmp(name,stu[i].name)==0)
        {
            in=i;
            break;
        }
    }
    return in;
}
int search_roll()
{
    int in=-1,i,roll;
    printf("Enter the roll of the student to search: ");
    scanf("%d",&roll);
    for(i=0;i<=top;i++)
    {
        if(roll==stu[i].roll)
        {
            in=i;
            break;
        }
    }
    return in;
}