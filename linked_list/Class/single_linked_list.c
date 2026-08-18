                                                // EXPERIMENT NO. 3        
/*Write a c program to create a single linked list and perform 
various operations: 
a) Insertion at: i) Beg ii) End iii) 
Any position 
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
    void sort();
    void reverse();
    void delete_beg();
    void delete_end();
    void delete_pos();

    create();
    traverse();
    insert_beg();
    insert_end();
    traverse();
    insert_pos();
    traverse();
    sort();
    traverse();
    reverse();
    traverse();
    reverse();
    delete_beg();
    traverse();
    delete_end();
    traverse();
    delete_pos();
    traverse();
    return 0;
}

// 1.CREATION

void create()
{
    int choice;
    struct node *ptr, *cpt;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter the info of ptr ");
    scanf("%d", &ptr->info);
    first = ptr;

    do
    {
        cpt = (struct node *)malloc(sizeof(struct node));
        printf("enter the info of cpt ");
        scanf("%d", &cpt->info);
        ptr->link = cpt;
        ptr = cpt;
        printf("press 1/0 for more nodes ");
        scanf("%d", &choice);
        if (choice == 0)
        {
            break;
        }
    } while (choice == 1);
    ptr->link = NULL;
}

// 2.TRAVERSING

void traverse()
{
    struct node *A;

    A = first;
    while (A != NULL)
    {
        printf("%d\t", A->info);
        A = A->link;
    }
    printf("\n");
}

// 3.INSERTION

void insert_beg()

{
    struct node *x;

    x = (struct node *)malloc(sizeof(struct node));
    printf("enter the info of node to be inserted at the begining ");
    scanf("%d", &x->info);
    x->link = first;
    first = x;
}

void insert_end()
{
    struct node *a;
    a = first;
    while (a->link != NULL)

    {
        a = a->link;
    }
    struct node *x;
    x = (struct node *)malloc(sizeof(struct node));
    printf("enter the info of the node to be inserted at the end ");
    scanf("%d", &x->info);

    a->link = x;
    x->link = NULL;
    printf("Linked list: ");
}

void insert_pos()
{
    int pos, i = 1;
    struct node *x, *y;

    printf("Enter position to insert node: ");
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

    while (i < pos - 1 && x != NULL)
    {
        x = x->link;
        i++;
    }

    if (x == NULL)
    {
        printf("Position out of range.\n");
        return;
    }

    y = (struct node *)malloc(sizeof(struct node));
    printf("enter the info of the node to be inserted ");
    scanf("%d", &y->info);

    y->link = x->link;
    x->link = y;
}

// 4.SORTING

void sort()
{
    struct node *X, *Y;
    X = first;
    while (X != NULL)
    {
        Y = X->link;
        while (Y != NULL)
        {
            if (X->info > Y->info)
            {
                int temp;
                temp = X->info;
                X->info = Y->info;
                Y->info = temp;
            }
            Y = Y->link;
        }
        X = X->link;
    }
    printf("Sorting: ");
}

// 5.REVERSE

void reverse()
{
    struct node *X, *Y;
    struct node *Z;
    X = first;
    Y = NULL;
    while (X != NULL)
    {
        Z = X->link;
        X->link = Y;
        Y = X;
        X = Z;
    }
    first = Y;
    printf("Reverse: ");
}

// 6.DELETION

void delete_beg()
{
    struct node *x, *y;
    x = first;
    if (first == NULL)
    {
        printf("List is empty. Nothing to be deleted.\n");
    }
    int choice;
    printf("Press 1/0 for first node to be deleted: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        y = x->link;
        first = y;
        free(x);

        printf("First node deleted successfully.\n");
    }
    else
    {
        printf("Deletion cancelled by the user.");
    }
}

void delete_end()
{
    struct node *x, *y;
    x = first;
    int choice;
    printf("Press 1/0 for end node to be deleted: ");
    scanf("%d", &choice);
    if (choice != 1)
    {
        printf("Deletion cancelled by the user.");
        return;
    }
    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if (first->link == NULL)
    {
        free(first);
        first = NULL;
        printf("Last node is deleted successfully.\n");
        return;
    }
    while (x->link != NULL)
    {
        y = x;
        x = x->link;
    }
    y->link = NULL;
    free(x);
    printf("Last node is deleted successfully.\n");
}

void delete_pos()
{
    int pos, i = 1;
    struct node *x, *y;

    printf("Enter position to delete node: ");
    scanf("%d", &pos);

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
    while (i < pos - 1 && x != NULL)
    {
        x = x->link;
        i++;
    }
    y = x->link;
    x->link = y->link;
    free(y);
    printf("Node at position %d deleted successfully.\n", pos);
}

// Simple Linked List Done