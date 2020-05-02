#include <stdio.h>
#include <stdlib.h>
struct N
{
    int data;
    struct N *next;
};
struct N *h1 = NULL, *h2 = NULL, *head = NULL;         // these are all the heads of the three pollynomial or the linked list.
struct N *create_node(int, struct N *);        // adds the newly crested node to the end of the linked list.
struct N *create(int);                         // creates a new node and returns it's address.
void display(struct N *);                           // traverse through the linked list and displays the values of every node.
struct N *merge(struct N *, struct N *, struct N *); // adds two pollynomials.
void main()
{
    int i;
    for(i=0;i<=10;i=i+2) // creating the first linked list.
    h1=create_node(i,h1);
    for(i=1;i<=10;i=i+2) // creating the second linked list.
    h2=create_node(i,h2);
    head=merge(h1,h2,head); // sorting the linked lists into a different linked list.
    //Display.
    printf("First linked list.\n");
    display(h1);
    printf("Second linked list.\n");
    display(h2);
    printf("Merged linked list.\n");
    display(head);
}
struct N* merge(struct N *h1, struct N *h2, struct N *head)
{
    struct N *temp,*t1,*t2;
    t1=h1;
    t2=h2;
    while (t1 && t2) // both the nodes are having some values.
    {
        if (t1->data < t2->data) // the node present into p1 will be transfered into p as it is.
        {
            head=create_node(t1->data,head);
            t1 = t1->next;
        }
        else if (t1->data > t2->data) // the node present into p2 will be transfered into p as it is.
        {
            head=create_node(t2->data, head);
            t2 = t2->next; // basic traversing.
        }
        else // if both the coeff are same.
        {
            head=create_node(t1->data, head);
            t1 = t1->next;
            t2 = t2->next;
        }
    } // someone in between p1 and p2 is end.
      // temp is simply asking for the remaining.
    for (temp = (t1) ? t1 : t2; temp; temp = temp->next)
        head=create_node(temp->data,head); //basic traversal.
    return head;
}

struct N* create_node(int data, struct N *head) // always adding at the end node.
{
    struct N *temp;
    temp = head;
    if (!head) //insertion at head
        head = create(data);
    else
    {
        while (temp->next) // traversing to the end.
        temp = temp->next;
        temp->next = create(data);
    }
    return head;
}
struct N *create(int data)
{
    struct N *temp;
    int x;
    temp = (struct N *)malloc(sizeof(struct N));
    temp->data = data;
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
        printf("The linked list is: \n");
        temp = head;
        while (temp->next)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}