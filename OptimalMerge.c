#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Min-heapify function to maintain the heap property
void minHeapify(int heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

// Function to build a min-heap
void buildMinHeap(int heap[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(heap, n, i);
}

// Function to extract the minimum element from the heap
int extractMin(int heap[], int *n) {
    int min = heap[0];
    heap[0] = heap[--(*n)];
    minHeapify(heap, *n, 0);
    return min;
}

// Optimal Merge Pattern function
int optimalMerge(int files[], int n) {
    int totalCost = 0;

    // Build a min-heap from the initial file sizes
    buildMinHeap(files, n);

    while (n > 1) {
        // Extract two smallest files
        int firstMin = extractMin(files, &n);
        int secondMin = extractMin(files, &n);

        // Calculate the merge cost and add back to heap
        int mergeCost = firstMin + secondMin;
        totalCost += mergeCost;
        files[n++] = mergeCost;  // Add merged file back to heap
        buildMinHeap(files, n);   // Rebuild min-heap
    }
    return totalCost;
}

int main() {
    int files[] = {4, 3, 2, 6};  // Example file sizes
    int n = sizeof(files) / sizeof(files[0]);

    int totalCost = optimalMerge(files, n);
    printf("Total minimum cost of merging files: %d\n", totalCost);

    return 0;
}
