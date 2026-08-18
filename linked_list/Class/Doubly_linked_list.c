                                                  // EXPERIMENT NO. 4
/*Write a c program to create a Doubly linked list and perform 
various operations: 
a) Insertion at: i) Beg ii) End iii) Any position 
b) Deletion from: i) Beg ii) End iii) Any position*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *lpt;
    struct node *rpt;
};
struct node *first;

int main(void)
{
    void create();
    void forward_traverse();
    void backward_traverse();
    void insert_beg();
    void insert_end();
    void insert_pos();
    void delete_beg();
    void delete_end();
    void delete_pos();
    

    create();
    forward_traverse();
    backward_traverse();
    insert_beg();
    insert_end();
    insert_pos();
    forward_traverse();
    delete_beg();
    forward_traverse();
    delete_end();
    forward_traverse();
    delete_pos();
    forward_traverse();
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
    ptr->lpt = NULL;
    ptr->rpt = NULL;
    first = ptr;

    do
    {
        cpt = (struct node *)malloc(sizeof(struct node));
        printf("enter the info of cpt: ");
        scanf("%d", &cpt->info);

        ptr->rpt = cpt;
        cpt->lpt = ptr;

        ptr = cpt;

        printf("press 1/0 for more nodes ");
        scanf("%d", &choice);
    } while (choice == 1);
    ptr->rpt = NULL;
}

// 2.TRAVERSING

void forward_traverse()
{
    struct node *A;
    A = first;
    printf("forward traverse: ");
    while (A != NULL)
    {
        printf("[%p  %d  %p]", (void *)A->lpt, A->info, (void *)A->rpt);
        A = A->rpt;
    }
    printf("\n");
}

void backward_traverse()
{
    struct node *X;
    X = first;
    while (X->rpt != NULL)
    {
        X = X->rpt;
    }
    printf("backward travesre: ");
    while (X != NULL)
    {
        printf("[%p  %d  %p]", (void *)X->lpt, X->info, (void *)X->rpt);
        X = X->lpt;
    }
    printf("\n");
}

// 3.INSERTION

void insert_beg()
{
    struct node *new, *Y;
    Y = first;
    new = (struct node *)malloc(sizeof(struct node));
    printf("enter the info of new node to be inserted at begining : ");
    scanf("%d", &new->info);
    Y->lpt = new;
    new->rpt = Y;
    new->lpt = NULL;
    first = new;
}

void insert_end()
{
    struct node *X, *Y;
    Y = (struct node *)malloc(sizeof(struct node));
    printf("enter the info of Y node to be inserted at end: ");
    scanf("%d", &Y->info);

    X = first;
    while (X->rpt != NULL)
    {
        X = X->rpt;
    }
    X->rpt = Y;
    Y->lpt = X;
    Y->rpt = NULL;
}

void insert_pos()
{
    int pos, i = 1;
    struct node *x, *y;
    printf("enter position to insert node: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("invalid position\n");
        return;
    }

    if (pos == 1)
    {
        insert_beg();
        return;
    }

    x = first;
    while (i < pos - 1 && x != NULL)
    {
        x = x->rpt;
        i++;
    }
    if (x == NULL)
    {
        printf("invalid position\n");
        return;
    }
    y = (struct node *)malloc(sizeof(struct node));
    printf("enter the info node to be inserted: ");
    scanf("%d", &y->info);

    y->rpt = x->rpt;
    y->lpt = x;

    if (x->rpt != NULL)
    {
        x->rpt->lpt = y;
    }
    x->rpt = y;
}

// 4. DELETION

void delete_beg()
{
    if (first == NULL)
    {
        printf("List is already empty.\n");
        return;
    }
    struct node *x;
    x = first;
    first = x->rpt;
    if (first != NULL)
    {
        first->lpt = NULL;
    }

    free(x);
    printf("First node deleted successfully.\n ");
}

void delete_end()
{
    if (first == NULL)
    {
        printf("The list is already empty.");
        return;
    }
    struct node *x, *y;
    x = first;
    while (x->rpt != NULL)
    {
        y = x;
        x = x->rpt;
    }
    y->rpt = NULL;
    free(x);

    printf("The end node is deleted.\n");
}

void delete_pos()
{
    int pos, i = 1;
    struct node *x, *y;
    printf("Enter the postion of node to be deleted: ");
    scanf("%d", &pos);

    if (pos < 1 || first == NULL)
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
    while (i < pos - 1)
    {
        x = x->rpt;
        i++;
    }
    y = x->rpt;
    x->rpt = y->rpt;
    if (y->rpt != NULL)
    {
        y->rpt->lpt = x;
    }
    free(y);
    printf("Node at position %d deleted successfully.\n", pos);
}

// DOUBLY LINKED LIST DONE.