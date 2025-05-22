#include <stdbool.h>
#include <stdio.h>

#define N 4

void printBoard(int board[N][N]) {
  for (int row = 0; row < N; row++) {
    for (int col = 0; col < N; col++) {
      printf("%d ", board[row][col]);
    }
    printf("\n");
  }
}

bool isSafe(int board[N][N], int row, int col) {
  for (int i = 0; i < col; i++)
    if (board[row][i]) return false;

  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (board[i][j]) return false;

  for (int i = row, j = col; i < N && j >= 0; i++, j--)
    if (board[i][j]) return false;

  return true;
}

bool solveNQUtil(int board[N][N], int col) {
  if (col >= N) {
    printBoard(board);
    printf("\n");
    return true;
  }

  bool foundSolution = false;
  for (int row = 0; row < N; row++) {
    if (isSafe(board, row, col)) {
      board[row][col] = 1;
      foundSolution = solveNQUtil(board, col + 1) || foundSolution;
      board[row][col] = 0;  // Backtrack
    }
  }
  return foundSolution;
}

void solveNQ() {
  int board[N][N] = {0};
  if (!solveNQUtil(board, 0)) {
    printf("Solution does not exist\n");
  }
}

int main() {
  solveNQ();
  return 0;
}