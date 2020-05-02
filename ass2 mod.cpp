#include<stdio.h>
#include<stdlib.h>
void add();
void search();
void modify();
void display();
struct student
{
	int roll;
	char name[50];
	float percentage;
	struct student *address;
};
int nodes=0;//nodes variable keeps the data of the total no of nodes present in to the inked list.
struct student *head;
head=NULL;
int main()
{
	int choice;
	char mychoice='y';
	//head=NULL;
	do
	{
		printf("Enter 1 to add a node.\nEnter 2 to display all existing record.\nEnter 3 to search a record.\nEnter 4 to modify an existing record.\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				add();
				display();
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
				printf("Enter any of the correct input.\n");
				break;
		}
		printf("\nDo you want to continue? [Y/N]");
			scanf(" %c",&mychoice);
	}while(mychoice=='y'||mychoice=='Y');
	return 0;
}
void add()
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
}
void display()
{
	struct student *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("\nThe name of the student is: %s\nThe roll no of the student is: %d \nThe percentage of the student is: %5.2f \n\n",temp->name,temp->roll,temp->percentage);
		temp=temp->address;
	}
}
void search()
{
}

void modify()
{
}
