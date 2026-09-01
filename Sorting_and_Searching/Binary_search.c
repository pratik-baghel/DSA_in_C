#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int beg = 0;
    int end = size - 1;

    while (beg <= end) {
        int mid = (beg + end) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            beg = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int target;
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Ente key to be searched: ");
    scanf("%d",&target);
    
    int result = binarySearch(arr, size, target);
    
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }
    
    return 0;
}
