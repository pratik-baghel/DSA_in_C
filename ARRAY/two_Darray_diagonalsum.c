// PROGRAM 2(b)
// FIND THE DIFFERENCE OF SUM OF DIAGONAL ELEMENTS IN ARRAY.

#include <stdio.h>

int main()
{
    int arr[100][100], n;
    int primary = 0, secondary = 0;

    printf("Enter the order of square matrix: ");
    scanf("%d", &n);

    printf("Enter the elements in array:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 0; i < n; i++)
    {
        primary += arr[i][i];
        secondary += arr[i][n-i-1];
    }

    printf("The difference of the sum of diagonal elements = %d",
           primary - secondary);

    return 0;
} 
// THE DIFFERENCE OF SUM OF DIAGONAL ELEMENTS IN ARRAY DONE.
