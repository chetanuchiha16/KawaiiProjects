#include <stdio.h>
#include <stdbool.h>

#define N 4

// Function to print the current state of the chessboard
void displayBoard(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

// Function to check if placing a queen at (row, col) is safe
bool isPositionSafe(int board[N][N], int row, int col) {
    // Check left row
    for (int i = 0; i < col; i++) {
        if (board[row][i]) return false;
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }

    // Check lower-left diagonal
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) return false;
    }

    return true;
}

// Recursive utility to solve N-Queens
bool solveNQueensUtil(int board[N][N], int col) {
    if (col >= N) {
        displayBoard(board);
        printf("\n");
        return true;
    }

    bool hasSolution = false;

    for (int row = 0; row < N; row++) {
        if (isPositionSafe(board, row, col)) {
            board[row][col] = 1;

            hasSolution = solveNQueensUtil(board, col + 1) || hasSolution;

            board[row][col] = 0; // Backtrack
        }
    }

    return hasSolution;
}

// Main function to initiate solving
void solveNQueens() {
    int board[N][N] = {0}; // Now local to this function 🫶

    if (!solveNQueensUtil(board, 0)) {
        printf("No solution exists\n");
    }
}

int main() {
    solveNQueens();
    return 0;
}
