                                                 // EXPERIMENT NO. 5
/*Write a c program to create a Circular linked list and perform 
various operations: 
a) Insertion at: i) Beg ii) End iii) Any position 
b) Deletion from: i) Beg ii) End iii) Any position*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *first;

int main()
{
    void create();
    void traverse();
    void insert_beg();
    void insert_end();
    void insert_pos();
    void delete_beg();
    void delete_end();
    void delete_pos();

    create();
    traverse();
    insert_beg();
    traverse();
    insert_end();
    traverse();
    insert_pos();
    traverse();
    delete_beg();
    traverse();
    delete_end();
    traverse();
    delete_pos();
    traverse();

    return 0;
}
// 1. CREATION
void create()
{
    int choice;
    struct node *ptr, *cpt;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter the info of ptr: ");
    scanf("%d", &ptr->info);
    first = ptr;
    ptr->link = first;

    do
    {
        cpt = (struct node *)malloc(sizeof(struct node));
        printf("enter the info of cpt: ");
        scanf("%d", &cpt->info);
        ptr->link = cpt;
        ptr = cpt;
        ptr->link = first;
        printf("press 1/0 for more nodes: ");
        scanf("%d", &choice);
    } while (choice == 1);

    printf("\n");
}

// 2. TRAVERSING
void traverse()
{
    struct node *A;

    if (first == NULL)
    {
        return;
    }
    printf("circular linked list is working :\n");
    printf("address of the first node: %d\n", (void *)first);
    printf("elments are \n: ");

    A = first;
    do
    {
        printf("%d  %d\t", A->info, A->link);
        A = A->link;
    } while (A != first);

    printf("\n");
}

// INSERTION
void insert_beg()
{
    struct node *x, *y;
    x = (struct node *)malloc(sizeof(struct node));
    printf("Enter the info of node to be insert at begining: ");
    scanf("%d", &x->info);
    y = first;
    while (y->link != first)
    {
        y = y->link;
    }
    x->link = first;
    first = x;
    y->link = first;
    printf("\n");
}

void insert_end()
{
    struct node *x, *y;
    first = x;
    while (x->link != first)
    {
        x = x->link;
    }
    y = (struct node *)malloc(sizeof(struct node));
    printf("enter the info of node to be inserted at end: ");
    scanf("%d", &y->info);

    x->link = y;
    y->link = first;
    printf("\n");
}

void insert_pos()
{
    int pos, i = 1;
    struct node *x, *y;

    printf("enter the position to insert node: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1)
    {
        insert_beg();
        return;
    }
    x = first;
    while (i < pos - 1 && x->link != first)
    {
        x = x->link;
        i++;
    }
    y = (struct node *)malloc(sizeof(struct node));
    printf("enter the info of node to be inserted : ");
    scanf("%d", &y->info);

    y->link = x->link;
    x->link = y;
    printf("\n");
}

// DELETION

void delete_beg()
{
    if (first == NULL)
    {
        printf("List is empty. Nothing to be deleted.\n");
        return;
    }
    struct node *x, *y, *last;
    int choice;
    printf("Press 1/0 for first node to be deleted: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        x = first;
        y = first->link;

        if (x == y)
        {
            first = NULL;
        }
        else
        {
            struct node *last = first;
            while (last->link != first)
            {
                last = last->link;
            }
            first = y;
            last->link = y;
        }

        free(x);
        printf("First node deleted successfully: \n");
    }
    else
    {
        printf("Deletion cancelled by the user.\n");
    }
}

void delete_end()
{
    struct node *x, *y;
    x = first;
    int choice;
    printf("press 1/0 for end node to be deleted: ");
    scanf("%d", &choice);
    if (choice != 1)
    {
        printf("Deletion cancelled by the user. \n");
        return;
    }

    while (x->link != first)
    {
        y = x;
        x = x->link;
    }
    y->link = first;
    free(x);
    printf("Last node is deleted successfully.\n");
} 

void delete_pos()
{
    int pos, i = 1;
    struct node *x,*y;

    printf("Enter position of node to be deleted: ");
    scanf("%d",&pos);

     if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1)
    {
        delete_beg();
        return;
    }

    x = first;
    while(i < pos && x->link != first)
    {
        y = x;
        x = x->link;
        i++;
    }
    y->link = x ->link;
    free(x); 
    printf("Node at position %d deleted successfully.\n", pos);
}

// CIRCULAR LINKED LIST IS COMPLETED.