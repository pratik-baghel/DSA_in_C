// EXPERIMENT NO. 2
/*Write a C program to perform various operations 2D array:
a) Multiplication of 2 matrix
b) Finding difference of sum of two diagonal elements.*/

// PROGRAM.2(a)
// MULTIPLICATION OF ARRAY.

#include <stdio.h>

int main()
{
    int arr1[100][100], arr2[100][100], arr3[100][100];
    int r1, c1, r2, c2;

    printf("Enter the number of rows and coloumn of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter the number of rows and column of second matrix: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter the first matrix: \n");

    for (int i = 0; i < r1; i++)
    {
        printf("Enter row %d: ", i + 1);
        for (int j = 0; j < c1; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Enter the second matrix: \n");

    for (int i = 0; i < r2; i++)
    {
        printf("Enter row %d: ", i + 1);
        for (int j = 0; j < c2; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }

    if (c1 != r2)
    {
        printf("Multiplication is not possible: \n");
        return 0;
    }

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            arr3[i][j] = 0;

            for (int k = 0; k < c1; k++)
            {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    printf("Result matrix \n");

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d ", arr3[i][j]);
        }

        printf("\n");
    }

    return 0;
} 
// MULTIPLICATION OF ONE-D ARRAY DONE.