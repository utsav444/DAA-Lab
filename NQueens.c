#include <stdio.h>

#define N 4  // Define the size of the chessboard

int board[N][N];

// Function to check if placing a queen at board[row][col] is safe
int isSafe(int row, int col) {
    // Check the row on the left
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    // Check the upper diagonal on the left
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Check the lower diagonal on the left
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

// Recursive function to solve the N-Queens problem
int solveNQueens(int col) {
    if (col >= N)  // All queens are placed
        return 1;

    for (int i = 0; i < N; i++) {  // Try placing a queen in each row of the current column
        if (isSafe(i, col)) {  // Check if it's safe to place a queen here
            board[i][col] = 1;  // Place the queen

            if (solveNQueens(col + 1))  // Recursively place the remaining queens
                return 1;

            board[i][col] = 0;  // If placing queen here leads to a solution, backtrack
        }
    }
    return 0;  // No solution found in this configuration
}

// Function to print the board
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

int main() {
    if (solveNQueens(0))
        printBoard();
    else
        printf("No solution exists\n");

    return 0;
}
