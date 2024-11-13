#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        int *b = (int *)malloc((ub - lb + 1) * sizeof(int));
        int i = lb, j = mid + 1, m = 0, k;

        while (i <= mid && j <= ub) {
            if (arr[i] < arr[j]) {
                b[m] = arr[i];
                i++;
            } else {
                b[m] = arr[j];
                j++;
            }
            m++;
        }
        while (i <= mid) {
            b[m] = arr[i];
            i++;
            m++;
        }
        while (j <= ub) {
            b[m] = arr[j];
            j++;
            m++;
        }
        for (k = 0; k < m; k++) {
            arr[lb + k] = b[k];
        }
        free(b);
    }
}

void merge_sort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        merge_sort(arr, lb, mid);      // Sort the left subarray
        merge_sort(arr, mid + 1, ub);  // Sort the right subarray
        merge(arr, lb, ub);            // Merge the two sorted subarrays
    }
}

int main() {
    int arr[100];
    int arr_size;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &arr_size);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < arr_size; i++) {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, arr_size - 1);

    printf("Sorted array: ");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
