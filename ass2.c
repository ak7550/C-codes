#include<stdio.h>
#include<stdlib.h>
struct student* add(struct student*);
struct student* search(struct student*);
struct student* modify(struct student*);
void display(struct student* head);
struct student
{
	int roll;
	char name[50];
	float percentage;
	struct student *address;
};
int nodes=0;//nodes variable keeps the data of the total no of nodes present in to the inked list.
int main()
{
	struct student *head;
	int choice;
	char mychoice='y';
	head=NULL;
	do
	{
		printf("Enter 1 to add a node.\nEnter 2 to display all existing record.\nEnter 3 to search a record.\nEnter 4 to modify an existing record.\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				head=add(head);
				display(head);
				//break;
			case 2:
				display(head);
				break;
			case 3:
				head=search(head);
				break;
			case 4:
				head=modify(head);
				break;
			default:
				printf("Enter any of the correct input.\n");
				break;
		}
		printf("\nDo you want to continue? [Y/N]");
			scanf(" %c",&mychoice);
	}while(mychoice=='y'||mychoice=='Y');
	return 0;
}

struct student* add(struct student* head)
{
	struct student *node,*temp;
	node=(struct student*)malloc(sizeof(struct student));
	temp=head;
	printf("Enter the name of the student: ");
	scanf("%s",&(node->name));
	printf("Enter the roll of the student: ");
	scanf("%d",&(node->roll));
	printf("Enter the percentage: ");
	scanf("%f",&(node->percentage));
	node->address=NULL;
	if(head==NULL) // Implies an empty list.
		head=node;
	else
	{
		temp=head;
		while(temp!=NULL)//Traversing to the last node.
			temp=temp->address;
		temp=node;
	}
	nodes++;
	return head;
}

struct student* search(struct student* head)
{
	
	return head;
}

struct student* modify(struct student* head)
{
	int m,i;
	struct student *temp;
	temp=head;
	printf("Enter the index no of node you wanna change: ");
	scanf("%d",&m);
	if(m>nodes)
		printf("%dth node does not exist.",m);
	else
		{
			for(i=0;i<m;i++)// Traversing node to node to go to the mth node.
				temp=temp->address;
			printf("Enter the new name of the student: ");
			scanf("%s",&(temp->name));
			printf("Enter the new roll of the student: ");
			scanf("%d",&(temp->roll));
			printf("Enter the new percentage: ");
			scanf("%f",&(temp->percentage));
		}
	return head;
}

void display(struct student* head)
{
	struct student *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("\nThe name of the student is: %s\nThe roll no of the student is: %d \nThe percentage of the student is: %5.2f \n\n",temp->name,temp->roll,temp->percentage);
		temp=temp->address;
	}
}
