#include <string>
#include <vector>

using namespace std;

/**
 * @brief 0051 N-Queens (Hard)
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n chessboard
 * such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle. You
 * may return the answer in any order.
 *
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space,
 * respectively.
 *
 * T(n) = O(n!)
 * S(n) = O(n^2)
 */
class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> n_queens(n, string(n, '.'));

    solveNQueens(res, n_queens, 0, n);

    return res;
  }

 private:
  void solveNQueens(vector<vector<string>> &res, vector<string> &n_queens,
                    int row, int &n) {
    if (row == n) {
      res.push_back(n_queens);
      return;
    }

    for (int col = 0; col != n; ++col)
      if (IsValid(n_queens, row, col, n)) {
        n_queens[row][col] = 'Q';
        solveNQueens(res, n_queens, row + 1, n);
        n_queens[row][col] = '.';
      }
  }

  bool IsValid(vector<string> &n_queens, int row, int col, int &n) {
    // check if the column had a queen before.
    for (int i = 0; i != row; ++i) {
      if (n_queens[i][col] == 'Q') {
        return false;
      }
    }

    // check if the 45° diagonal had a queen before.
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
      if (n_queens[i][j] == 'Q') {
        return false;
      }
    }

    // check if the 135° diagonal had a queen before.
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
      if (n_queens[i][j] == 'Q') {
        return false;
      }
    }

    return true;
  }
};

class Solution2 {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> g(n, string(n, '.'));
    vector<bool> col(n, false);
    vector<bool> dg(2 * n, false);
    vector<bool> udg(2 * n, false);
    dfs(0, n, col, dg, udg, g, res);
    return res;
  }

  void dfs(int u, int n, vector<bool> &col, vector<bool> &dg, vector<bool> &udg,
           vector<string> &g, vector<vector<string>> &res) {
    if (u == n) {
      res.push_back(g);
      return;
    }

    for (int i = 0; i < n; ++i) {
      if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
        g[u][i] = 'Q';
        col[i] = dg[u + i] = udg[n - u + i] = true;
        dfs(u + 1, n, col, dg, udg, g, res);
        g[u][i] = '.';
        col[i] = dg[u + i] = udg[n - u + i] = false;
      }
    }
  }
};
