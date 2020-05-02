#include <stdio.h>
#include <stdlib.h>
struct N
{
    int data, pow;
    struct N *next;
};
struct N *p1 = NULL, *p2 = NULL, *p = NULL;         // these are all the heads of the three pollynomial or the linked list.
struct N *create_node(int, int, struct N *);        // adds the newly crested node to the end of the linked list.
struct N *create(int, int);                         // creates a new node and returns it's address.
void display(struct N *);                           // traverse through the linked list and displays the values of every node.
struct N *padd(struct N *, struct N *, struct N *); // adds two pollynomials.
void main()
{
    // Create first list of 5x^2 + 4x^1 + 2x^0
    p1=create_node(5, 2, p1);
    p1=create_node(4, 1, p1);
    p1=create_node(2, 0, p1);
    // Create second list of 5x^1 + 5x^0
    p2=create_node(5, 1, p2); 
    p2=create_node(5, 0, p2);
    printf("1st Pollynomial: ");
    display(p1);
    printf("\n2nd Pollynoimal: ");
    display(p2);
    p=padd(p1, p2, p);             // Function add two pnomial numbers
    printf("\nAdded pnomial: "); // Display resultant List
    display(p);
}
struct N* padd(struct N *p1, struct N *p2, struct N *p)
{
    struct N *temp,*t1,*t2;
    t1=p1;
    t2=p2;
    while (t1 && t2) // both the nodes are having some values.
    {
        if (t1->pow > t2->pow) // the node present into p1 will be transfered into p as it is.
        {
            p=create_node(t1->data, t1->pow, p);
            t1 = t1->next;
        }
        else if (t1->pow < t2->pow) // the node present into p2 will be transfered into p as it is.
        {
            p=create_node(t2->data, t2->pow, p);
            t2 = t2->next; // basic traversing.
        }
        else // if both the coeff are same.
        {
            p=create_node(t1->data + t2->data, t1->pow, p);
            t1 = t1->next;
            t2 = t2->next;
        }
    } // someone in between p1 and p2 is end.
      // temp is simply asking for the remaining.
    for (temp = (t1) ? t1 : t2; temp; temp = temp->next)
        p=create_node(temp->data, temp->pow, p); //basic traversal.
    return p;
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