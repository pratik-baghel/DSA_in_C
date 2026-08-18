// EXPERIMENT NO. 1
/*Write a C program to create array and perform various operations:
a) Insertion at: i) Beg ii) End iii) Any position
b) Deletion from: i) Beg ii) End iii) Any position*/
#include <stdio.h>
#include <stdlib.h>

int arr[100];
int n;
int main()
{
    void create();
    void traverse();
    void insertAtBeg();
    void insertAtEnd();
    void insertAtPos();
    void deleteFromBeg();
    void deleteFromEnd();
    void deleteFromPos();

    create();
    traverse();
    insertAtBeg();
    traverse();
    insertAtEnd();
    traverse();
    insertAtPos();
    traverse();
    deleteFromBeg();
    traverse();
    deleteFromEnd();
    traverse();
    deleteFromPos();
    traverse();
    return 0;
}
// 1. CREATION
void create()
{
    printf("Enter the number of elements in array: ");
    scanf("%d", &n);

    printf("Enter element in array: \n");

    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
// 2. TRAVERSING
void traverse()
{
    if(n==0)
    {
        printf("Array is empty.\n");
    }
    printf("array elements: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// 3. INSERTION
void insertAtBeg()
{
    int value;
    printf("Enter the value to be inserted at begining: ");
    scanf("%d", &value);
    for(int i=n; i>0; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=value;
    n++;
}
void insertAtEnd()
{
    int value;
    printf("enter the value to be inserted at end: ");
    scanf("%d", &value);

    arr[n]=value;
    n++;
}
void insertAtPos()
{
    int value;
    int pos;
    printf("Enter the position of element to be inserted: ");
    scanf("%d", &pos);
    printf("Enter the value to be inserted at %d position: ",pos);
    scanf("%d", &value);


    if(pos<1 || pos>n+1)
    {
        printf("Invalid pos.");
    }

    for(int i=n; i>pos-1; i--)
    {
        arr[i]=arr[i-1];
    }

    arr[pos-1]=value;
    n++;
}
// 4. DELETION
void deleteFromBeg()
{
    if(n==0)
    {
        printf("Array is empty.");
        return;
    }
    for(int i=0; i<n-1; i++)
    {
        arr[i]=arr[i+1];
    }
    n--;
    printf("first element is deleted successfully.\n");
}
void deleteFromEnd()
{
    if(n==0)
    {
        printf("Array is empty.");
        return;
    }
    n--;
    printf("Last element is deleted successfully.\n");
}
void deleteFromPos()
{
    int pos;

    printf("Enter the element position to be deleted: ");
    scanf("%d",&pos);

    if(pos<1 || pos>n)
    {
        printf("INvalid positon. ");
    }

    for(int i=pos-1; i<n-1; i++)
    {
        arr[i]=arr[i+1];
    }
    n--; 
    printf(" %d position element deleted successfully.\n",pos);
}
// 1-D ARRAY COMPLETE.