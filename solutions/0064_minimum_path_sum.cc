#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief 0064 Minimum Path Sum (Medium)
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right, which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 * T(n) = O(m * n)
 * S(n) = O(n)
 *
 */
class Solution {
 public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> cur(m, grid[0][0]);

    for (int i = 1; i < m; i++) {
      cur[i] = cur[i - 1] + grid[i][0];
    }

    for (int j = 1; j < n; j++) {
      cur[0] += grid[0][j];
      for (int i = 1; i < m; i++) {
        cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
      }
    }

    return cur[m - 1];
  }
};

class Solution2 {
 public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> sum(m, vector<int>(n, grid[0][0]));

    for (int i = 1; i < m; i++) {
      sum[i][0] = sum[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < n; j++) {
      sum[0][j] = sum[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
      }
    }

    return sum[m - 1][n - 1];
  }
};
