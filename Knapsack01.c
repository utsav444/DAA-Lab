#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, int weights[], int values[], int n) {
    int dp[n + 1][W + 1];

    // Build table dp[][] in a bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;  // Initialize the first row and column to 0
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];  // Maximum value for the given weight limit
}

int main() {
    int values[] = {60, 100, 120};  // Values of items
    int weights[] = {10, 20, 30};   // Weights of items
    int W = 50;                     // Maximum weight capacity of the knapsack
    int n = sizeof(values) / sizeof(values[0]);

    int max_value = knapsack(W, weights, values, n);
    printf("Maximum value in Knapsack = %d\n", max_value);

    return 0;
}
