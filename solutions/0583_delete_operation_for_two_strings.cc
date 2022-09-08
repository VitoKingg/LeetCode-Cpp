#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 0583 Delete Operation for Two Strings (Medium)
 *
 * Given two strings word1 and word2, return the minimum number of steps
 * required to make word1 and word2 the same.
 *
 * In one step, you can delete exactly one character in either string.
 *
 */

// Solution：Dynamic Programming Space-Optimized
// Time:  O(m * n)
// Space: O(n)
class Solution {
 public:
  int minDistance(string word1, string word2) {
    const auto m = word1.length();
    const auto n = word2.length();
    vector<vector<int>> dp(2, vector<int>(n + 1));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[(i + 1) % 2][j + 1] = max(max(dp[i % 2][j + 1], dp[(i + 1) % 2][j]),
                                     dp[i % 2][j] + (word1[i] == word2[j]));
      }
    }

    return m + n - 2 * dp[m % 2][n];
  }
};

// Solution：Dynamic Programming - Tabulation
// Time:  O(m * n)
// Space: O(m * n)
class Solution {
 public:
  int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= n; j++) {
        if (!i || !j) {
          dp[i][j] = i + j;
        } else {
          dp[i][j] = word1[i - 1] == word2[j - 1]
                         ? dp[i - 1][j - 1]
                         : 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[m][n];
  }
};
