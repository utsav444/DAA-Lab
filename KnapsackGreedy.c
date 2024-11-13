#include <stdio.h>

struct Item {
    int weight;
    int value;
};

// Function to perform the greedy approach for fractional knapsack
float fractionalKnapsack(int W, struct Item items[], int n) {
    // Calculate value-to-weight ratio and sort items by this ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            float r1 = (float)items[j].value / items[j].weight;
            float r2 = (float)items[j + 1].value / items[j + 1].weight;
            if (r1 < r2) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    float totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (W >= items[i].weight) {
            // Take the whole item if it fits
            W -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take a fraction of the item
            totalValue += items[i].value * ((float)W / items[i].weight);
            break;  // Knapsack is full
        }
    }
    return totalValue;
}

int main() {
    struct Item items[] = { {10, 60}, {20, 100}, {30, 120} };  // Define items with weights and values
    int n = sizeof(items) / sizeof(items[0]);
    int W = 50;  // Maximum weight capacity of knapsack

    float max_value = fractionalKnapsack(W, items, n);
    printf("Maximum value in Knapsack = %.2f\n", max_value);

    return 0;
}
