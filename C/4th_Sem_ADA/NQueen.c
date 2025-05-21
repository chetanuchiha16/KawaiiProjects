#include <stdio.h>
#include <stdbool.h>

#define N 4

int board[N][N];

// Function to print the board
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Function to solve the N-Queens problem using backtracking
bool solveNQUtil(int col) {
    if (col >= N) {
        printBoard();
        printf("\n");
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            res = solveNQUtil(col + 1) || res;
            board[i][col] = 0; // Backtrack
        }
    }

    return res;
}

// Function to solve the N-Queens problem
void solveNQ() {
    if (!solveNQUtil(0)) {
        printf("Solution does not exist");
    }
}

int main() {
    solveNQ();
    return 0;
}