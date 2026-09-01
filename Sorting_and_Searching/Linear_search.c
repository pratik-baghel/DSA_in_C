#include <stdio.h>

void linearSearch(int A[], int N, int VAL) {
    int POS = -1;
    int I = 1;

    while (I <= N) {
        if (A[I] == VAL) {
            POS = I;
            printf("%d\n", POS);
            return;
        }
        I = I + 1;
    }
    if (POS == -1) {
        printf("VALUE IS NOT PRESENT IN THE ARRAY\n");
    }

    return;
}

int main() {
    int N, VAL;

    printf("Enter number of elements (N): ");
    scanf("%d", &N);

    int A[N + 1]; 

    printf("Enter %d integers:\n", N);
    for (int i = 1; i <= N; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }
    printf("Enter value to search (VAL): ");
    scanf("%d", &VAL);

    printf("\n--- Output ---\n");
    linearSearch(A, N, VAL);

    return 0;
}
