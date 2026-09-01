#include <stdio.h>

void TOH(int n, char A, char B, char C){
    if (n == 1) {
        printf("%c -> %c\n", A, C);
        return;
    }
    TOH(n - 1, A, C, B);
    printf("%c -> %c\n", A, C);
    TOH(n - 1, B, A, C);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    if (scanf("%d", &n) != 1) return 1;
    
    TOH(n, 'A', 'B', 'C');
    return 0;
}
