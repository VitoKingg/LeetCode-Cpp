#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 0072 Edit Distance (Hard)
 *
 * Given two strings word1 and word2, return the minimum number of operations
 * required to convert word1 to word2.
 *
 * You have the following three operations permitted on a word:
 *
 *    - Insert a character
 *    - Delete a character
 *    - Replace a character
 *
 */

// T(n) = O(m * n)
// S(n) = O(n)
class Solution {
 public:
  int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    int pre = 0;
    vector<int> cur(n + 1, 0);

    for (int i = 1; i <= n; i++) {
      cur[i] = i;
    }

    for (int i = 1; i <= m; i++) {
      pre = cur[0];
      cur[0] = i;
      for (int j = 1; j <= n; j++) {
        int temp = cur[j];
        if (word1[i - 1] == word2[j - 1]) {
          cur[j] = pre;
        } else {
          cur[j] = min(pre, min(cur[j - 1], cur[j])) + 1;
        }
        pre = temp;
      }
    }

    return cur[n];
  }
};

// T(n) = O(m * n)
// S(n) = O(m * n)
class Solution2 {
 public:
  int minDistance(string word1, string word2) {
    const int m = word1.length();
    const int n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 1; i <= m; ++i) {
      dp[i][0] = i;
    }

    for (int j = 1; j <= n; ++j) {
      dp[0][j] = j;
    }

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
        }
      }
    }

    return dp[m][n];
  }
};
