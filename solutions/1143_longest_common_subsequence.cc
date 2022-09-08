#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 1143 Longest Common Subsequence (Medium)
 *
 * Given two strings text1 and text2, return the length of their longest common
 * subsequence. If there is no common subsequence, return 0.
 *
 * A subsequence of a string is a new string generated from the original string
 * with some characters (can be none) deleted without changing the relative
 * order of the remaining characters.
 *
 *    - For example, "ace" is a subsequence of "abcde".
 *
 * A common subsequence of two strings is a subsequence that is common to both
 * strings.
 *
 */

// Solution1: DP Memory-Optimized
// Time:  O(nm)
// Space: O(min(n, m))
class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    const int m = text1.length();
    const int n = text2.length();

    if (m < n) {
      return longestCommonSubsequence(text2, text1);
    }

    vector<vector<int>> dp(2, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i % 2][j] = (text1[i - 1] == text2[j - 1])
                           ? dp[(i - 1) % 2][j - 1] + 1
                           : max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
      }
    }

    return dp[m % 2][n];
  }
};

// Solution2: DP
// T(n) = O(nm)
// S(n) = O(nm)
class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    const int m = text1.length();
    const int n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i + 1][j + 1] = text1[i] == text2[j]
                               ? 1 + dp[i][j]
                               : max(dp[i][j + 1], dp[i + 1][j]);
      }
    }

    return dp[m][n];
  }
};
