#include <stdio.h>

void swap(int arr[], int a, int b) 
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int arr[], int lb, int ub) 
{
    int pivot = arr[lb];
    int i = ub + 1;

    for (int j = ub; j > lb; j--) 
    {
        if (arr[j] >= pivot) 
        {
            i--;
            swap(arr, i, j);
        }
    }

    swap(arr, i - 1, lb);
    return i - 1;
}

void quickSort(int arr[], int lb, int ub) 
{
    if (lb < ub) 
    {
        int pi = partition(arr, lb, ub);

        quickSort(arr, lb, pi - 1);
        quickSort(arr, pi + 1, ub);
    }
}

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() 
{
    int arr[100];
    int arr_size;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &arr_size);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < arr_size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, arr_size - 1);

    printf("Sorted array: ");
    printArray(arr, arr_size);
    
    return 0;
}



