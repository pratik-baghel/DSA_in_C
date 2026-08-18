// EXPERIMENT NO. 6
// Write a c program to create two polynomials and add them.
#include <stdio.h>
#include <stdlib.h>

struct term
{
    int coeff, pow;
    struct term *add;
};
struct term *first, *second, *first3;
int main()
{
    void create1();
    void traverse(struct term *);
    void create2();
    void addition_poly();

    create1();
    traverse(first);
    create2();
    traverse(second);
    addition_poly();
    traverse(first3);
}

void create1()
{
    printf("enter first polynomial equation\n");
    int choice;
    struct term *ptr, *cpt;
    ptr = (struct term *)malloc(sizeof(struct term));
    printf("enter the coefficient : ");
    scanf("%d", &ptr->coeff);

    printf("enter power of equation: ");
    scanf("%d", &ptr->pow);
    first = ptr;
    do

    {
        cpt = (struct term *)malloc(sizeof(struct term));
        printf("enter the coefficient : ");
        scanf("%d", &cpt->coeff);

        printf("enter power of equation: ");
        scanf("%d", &cpt->pow);
        ptr->add = cpt;
        ptr = cpt;
        printf("press 1/0 for more nodes: ");
        scanf("%d", &choice);
        if (choice == 0)
        {
            break;
        }
    } while (choice == 1);
    ptr->add = NULL;
}

void traverse(struct term *a)
{
    while (a != NULL)
    {
        printf("[%dX^%d]", a->coeff, a->pow);
        a = a->add;
        if (a != NULL)
        {
            printf("+");
        }
    }
    printf("\n");
}

void create2()
{
    printf("enter second polynomial equation\n");
    int choice;
    struct term *ptr, *cpt;
    ptr = (struct term *)malloc(sizeof(struct term));
    printf("enter the coefficient : ");
    scanf("%d", &ptr->coeff);

    printf("enter power of equation: ");
    scanf("%d", &ptr->pow);
    second = ptr;
    do

    {
        cpt = (struct term *)malloc(sizeof(struct term));
        printf("enter the coefficient : ");
        scanf("%d", &cpt->coeff);

        printf("enter power of equation: ");
        scanf("%d", &cpt->pow);
        ptr->add = cpt;
        ptr = cpt;
        printf("press 1/0 for more nodes: ");
        scanf("%d", &choice);
        if (choice == 0)
        {
            break;
        }
    } while (choice == 1);
    ptr->add = NULL;
    printf("\n");
}

void addition_poly()
{
    printf("Addition of two polynomial:\n");
    struct term *ptr1, *ptr2, *ptr, *cpt;

    ptr = (struct term *)malloc(sizeof(struct term));
    ptr1 = first;
    ptr2 = second;
    first3 = ptr;

    if (ptr1->pow > ptr2->pow)
    {
        ptr->coeff = ptr1->coeff;
        ptr->pow = ptr1->pow;
        ptr1 = ptr1->add;
    }
    else if (ptr2->pow > ptr1->pow)
    {
        ptr->coeff = ptr2->coeff;
        ptr->pow = ptr2->pow;
        ptr2 = ptr2->add;
    }
    else
    {
        ptr->coeff = ptr1->coeff + ptr2->coeff;
        ptr->pow = ptr1->pow;
        ptr1 = ptr1->add;
        ptr2 = ptr2->add;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {
        cpt = (struct term *)malloc(sizeof(struct term));

        if (ptr1->pow > ptr2->pow)
        {
            cpt->coeff = ptr1->coeff;
            cpt->pow = ptr1->pow;
            ptr1 = ptr1->add;
        }
        else if (ptr2->pow > ptr1->pow)
        {
            cpt->coeff = ptr2->coeff;
            cpt->pow = ptr2->pow;
            ptr2 = ptr2->add;
        }
        else
        {
            cpt->coeff = ptr1->coeff + ptr2->coeff;
            cpt->pow = ptr1->pow;
            ptr1 = ptr1->add;
            ptr2 = ptr2->add;
        }

        ptr->add = cpt;
        ptr = cpt;
    }

    while (ptr1 != NULL)
    {
        cpt = (struct term *)malloc(sizeof(struct term));
        cpt->coeff = ptr1->coeff;
        cpt->pow = ptr1->pow;
        ptr1 = ptr1->add;
        ptr->add = cpt;
        ptr = cpt;
    }

    while (ptr2 != NULL)
    {
        cpt = (struct term *)malloc(sizeof(struct term));
        cpt->coeff = ptr2->coeff;
        cpt->pow = ptr2->pow;
        ptr2 = ptr2->add;
        ptr->add = cpt;
        ptr = cpt;
    }

    ptr->add = NULL;
}
// ADDITION OF TWO POLYNOMIAL DONE. 