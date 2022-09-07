#include <limits>
#include <queue>
#include <vector>

using namespace std;

/**
 * @brief 0542 01 Matrix (Medium)
 *
 * Given an m x n binary matrix mat, return the distance of the nearest 0 for
 * each cell.
 *
 * The distance between two adjacent cells is 1.
 *
 */

// Solution1: Dynamic Programming
// T(n) = O(m * n)
// S(n) = O(1)
class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();
    // The distance of cells is up to (M+N)
    int INF = m + n;

    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        if (mat[r][c] == 0) {
          continue;
        }

        int top = INF, left = INF;
        if (r - 1 >= 0) {
          top = mat[r - 1][c];
        }

        if (c - 1 >= 0) {
          left = mat[r][c - 1];
        }

        mat[r][c] = min(top, left) + 1;
      }
    }

    for (int r = m - 1; r >= 0; r--) {
      for (int c = n - 1; c >= 0; c--) {
        if (mat[r][c] == 0) {
          continue;
        }

        int bottom = INF, right = INF;
        if (r + 1 < m) {
          bottom = mat[r + 1][c];
        }

        if (c + 1 < n) {
          right = mat[r][c + 1];
        }

        mat[r][c] = min(mat[r][c], min(bottom, right) + 1);
      }
    }

    return mat;
  }
};

// Solution2: BFS
// T(n) = O(m * n)
// S(n) = O(m * n)
class Solution2 {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    const int m = mat.size();
    const int n = mat[0].size();
    queue<pair<int, int>> q;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 0) {
          q.emplace(i, j);
        } else {
          // std::numeric_limits<int>::max() defined in limits header
          mat[i][j] = numeric_limits<int>::max();
        }
      }
    }

    const vector<int> dirs{0, 1, 0, -1, 0};
    while (!q.empty()) {
      const auto [i, j] = q.front();
      q.pop();

      for (int k = 0; k < 4; ++k) {
        const int x = i + dirs[k];
        const int y = j + dirs[k + 1];

        if (x < 0 || x == m || y < 0 || y == n) {
          continue;
        }

        if (mat[x][y] <= mat[i][j] + 1) {
          continue;
        }

        q.emplace(x, y);
        mat[x][y] = mat[i][j] + 1;
      }
    }

    return mat;
  }
};
