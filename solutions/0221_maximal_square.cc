#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief 0221 Maximal Square (Medium)
 *
 * Given an m x n binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 *
 */

// Solution1: Space-Optimized Dynamic Programming
// T(n) = O(m * n)
// S(n) = O(1)
class Solution {
 public:
  int maximalSquare(vector<vector<char>> &matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<int> dp(n);
    int max_len = 0;
    int prev = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        const int cache = dp[j];

        if (i == 0 || j == 0 || matrix[i][j] == '0') {
          dp[j] = matrix[i][j] == '1' ? 1 : 0;

        } else {
          dp[j] = min({prev, dp[j], dp[j - 1]}) + 1;
        }

        max_len = max(max_len, dp[j]);
        prev = cache;
      }
    }

    return max_len * max_len;
  }
};

// Solution2: Dynamic Programming
// T(n) = O(m * n)
// S(n) = O(m * n)
class Solution2 {
 public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int mx = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == '1') {
          dp[i + 1][j + 1] = min(min(dp[i][j + 1], dp[i + 1][j]), dp[i][j]) + 1;
          mx = max(mx, dp[i + 1][j + 1]);
        }
      }
    }

    return mx * mx;
  }
};
