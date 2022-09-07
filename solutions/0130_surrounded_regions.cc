#include <queue>
#include <vector>

using namespace std;

/**
 * @brief 0130 Surrounded Regions (Medium)
 *
 * Given an m x n matrix board containing 'X' and 'O', capture all regions that
 * are 4-directionally surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 *
 * T(n) = O(m * n)
 * S(n) = O(m + n)
 */
class Solution {
 public:
  void solve(vector<vector<char>> &board) {
    if (board.empty()) {
      return;
    }

    const int m = board.size();
    const int n = board[0].size();

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i * j == 0 || i == m - 1 || j == n - 1) {
          dfs(board, i, j);
        }
      }
    }

    for (vector<char> &row : board) {
      for (char &c : row) {
        if (c == '*') {
          c = 'O';
        } else if (c == 'O') {
          c = 'X';
        }
      }
    }
  }

 private:
  // mark 'O' grids that stretch from four sides with '*'
  void dfs(vector<vector<char>> &board, int i, int j) {
    if (i < 0 || i == board.size() || j < 0 || j == board[0].size()) {
      return;
    }

    if (board[i][j] != 'O') {
      return;
    }

    board[i][j] = '*';
    dfs(board, i + 1, j);
    dfs(board, i - 1, j);
    dfs(board, i, j + 1);
    dfs(board, i, j - 1);
  }
};

class Solution2 {
 public:
  void solve(vector<vector<char>> &board) {
    if (board.empty()) {
      return;
    }

    const int m = board.size();
    const int n = board[0].size();
    const vector<int> dirs{0, 1, 0, -1, 0};
    queue<pair<int, int>> q;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i * j == 0 || i == m - 1 || j == n - 1) {
          if (board[i][j] == 'O') {
            q.emplace(i, j);
            board[i][j] = '*';
          }
        }
      }
    }

    // mark grids that stretch from four sides with '*'
    while (!q.empty()) {
      const auto [i, j] = q.front();
      q.pop();

      for (int k = 0; k < 4; ++k) {
        const int x = i + dirs[k];
        const int y = j + dirs[k + 1];

        if (x < 0 || x == m || y < 0 || y == n) {
          continue;
        }

        if (board[x][y] != 'O') {
          continue;
        }

        q.emplace(x, y);
        board[x][y] = '*';
      }
    }

    for (vector<char> &row : board) {
      for (char &c : row) {
        if (c == '*') {
          c = 'O';
        } else if (c == 'O') {
          c = 'X';
        }
      }
    }
  }
};
