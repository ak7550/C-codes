#include <stdio.h>
#include <stdlib.h>
#include<math.h>
struct N
{
    int data, pow;
    struct N *next;
};
struct N *p = NULL;         // these are all the heads of the three pollynomial or the linked list.
struct N *create_node(int, int, struct N *);        // adds the newly crested node to the end of the linked list.
struct N *create(int, int);                         // creates a new node and returns it's address.
void display(struct N *);    
float evaluate(struct N* head);
void main()
{
    // Create first list of 5x^2 + 4x^1 + 2x^0
    p=create_node(5, 2, p);
    p=create_node(4, 1, p);
    p=create_node(2, 0, p);
    printf("1st Pollynomial: ");
    display(p);
    printf("\n2nd Pollynoimal: ");
    display(p);
    printf("The evaluated value is: %f",evaluate(p));             // Function evaluate with the value of x;
    printf("\nAdded pnomial: "); // Display resultant List
    display(p);
}  
float evaluate(struct N* head)
{
    struct N *temp;
    temp=head;
    float sum,x;
    printf("Enter the value of x: ");
    scanf("%f",&x);
    while (temp)
    {
        sum+=temp->data*pow(x,temp->pow);
        temp=temp->next;
    }
    return sum;
}
struct N* create_node(int data, int pow, struct N *head) // always adding at the end node.
{
    struct N *temp;
    temp = head;
    if (!head) //insertion at head
        head = create(data, pow);
    else
    {
        while (temp->next) // traversing to the end.
        temp = temp->next;
        temp->next = create(data, pow);
    }
    return head;
}
struct N *create(int data, int pow)
{
    struct N *temp;
    int x;
    temp = (struct N *)malloc(sizeof(struct N));
    temp->data = data;
    temp->pow = pow;
    temp->next = NULL;
    return temp;
}
void display(struct N *head)
{
    struct N *temp;
    if (!head)
        printf("\nThe Linked list is empty. Nothing is to show.\n");
    else
    {
        printf("\nThe linked list are: \n");
        temp = head;
        while (temp->next)
        {
            printf("Coefficient is: %d\t Power: %d\n", temp->data, temp->pow);
            temp = temp->next;
        }
        printf("Coefficient is: %d\t Power: %d\n", temp->data, temp->pow);
    }
}