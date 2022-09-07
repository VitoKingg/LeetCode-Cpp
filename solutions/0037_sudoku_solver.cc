#include <vector>

using namespace std;

/**
 * @brief 0037 Sudoku Solver (Hard)
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * A sudoku solution must satisfy all of the following rules:
 *
 *    - Each of the digits 1-9 must occur exactly once in each row.
 *    - Each of the digits 1-9 must occur exactly once in each column.
 *    - Each of the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 *
 * The '.' character indicates empty cells.
 *
 * T(n) = O(9^2)
 * S(n) = O(9)
 */
class Solution {
 public:
  void solveSudoku(vector<vector<char>> &board) { solve(board, 0); }

 private:
  bool solve(vector<vector<char>> &board, int s) {
    if (s == 81) {
      return true;
    }

    const int i = s / 9;
    const int j = s % 9;

    if (board[i][j] != '.') {
      return solve(board, s + 1);
    }

    for (char c = '1'; c <= '9'; ++c) {
      if (isValid(board, i, j, c)) {
        board[i][j] = c;
        if (solve(board, s + 1)) {
          return true;
        }
        board[i][j] = '.';
      }
    }

    return false;
  }

  bool isValid(vector<vector<char>> &board, int row, int col, char c) {
    for (int i = 0; i < 9; ++i) {
      if (board[i][col] == c || board[row][i] == c ||
          board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
        return false;
      }
    }

    return true;
  }
};
