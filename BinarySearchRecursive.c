#include <stdio.h>
#include <stdlib.h>

int binarySearchRecursive(int arr[], int x, int l, int r) {
    if (l > r) {
        return 0; // Element not found
    }

    int mid = (l + r) / 2;

    if (arr[mid] == x) {
        return mid;
    } else if (arr[mid] > x) {
        return binarySearchRecursive(arr, x, l, mid - 1);
    } else {
        return binarySearchRecursive(arr, x, mid + 1, r);
    }
}

int main() {
    int mid, l, r, i, n, x, arr[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements in ascending order: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element you want to search: ");
    scanf("%d", &x);

    l = 0;
    r = n - 1;

    int found = binarySearchRecursive(arr, x, l, r);

    if (found) {
        printf("Element found.");
    } else {
        printf("No element Found.");
    }

    return 0;
}
