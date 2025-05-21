#include <stdio.h>
#include <stdbool.h>

#define N 4

// Chessboard representation
int chessboard[N][N];

// Function to print the current state of the chessboard
void displayBoard() {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", chessboard[row][col]);
        }
        printf("\n");
    }
}

// Function to check if placing a queen at (row, col) is safe
bool isPositionSafe(int row, int col) {
    // Check left side of the current row
    for (int i = 0; i < col; i++) {
        if (chessboard[row][i]) {
            return false;
        }
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (chessboard[i][j]) {
            return false;
        }
    }

    // Check lower left diagonal
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (chessboard[i][j]) {
            return false;
        }
    }

    return true;
}

// Recursive utility to solve N-Queens using backtracking
bool solveNQueensUtil(int col) {
    // All queens are placed
    if (col >= N) {
        displayBoard();
        printf("\n");
        return true;
    }

    bool hasSolution = false;

    // Try placing queen in each row of the current column
    for (int row = 0; row < N; row++) {
        if (isPositionSafe(row, col)) {
            chessboard[row][col] = 1; // Place queen

            // Recur to place rest of the queens
            hasSolution = solveNQueensUtil(col + 1) || hasSolution;

            chessboard[row][col] = 0; // Backtrack
        }
    }

    return hasSolution;
}

// Main function to initiate solving
void solveNQueens() {
    if (!solveNQueensUtil(0)) {
        printf("No solution exists\n");
    }
}

int main() {
    solveNQueens();
    return 0;
}
