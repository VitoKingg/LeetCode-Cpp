#include <string>
#include <vector>

using namespace std;

/**
 * @brief 0010 Regular Expression Matching (Hard)
 *
 * Given an input string s and a pattern p, implement regular expression
 * matching with support for '.' and '*' where:
 *
 *    - '.' Matches any single character.​​​​
 *    - '*' Matches zero or more of the preceding element.
 *
 * The matching should cover the entire input string (not partial).
 *
 */

// Solution1: dp space optimized
// T(n) = O()
// S(n) = O()
class Solution {
 public:
  bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector<bool> cur(n + 1, false);

    for (int i = 0; i <= m; i++) {
      bool pre = cur[0];
      cur[0] = !i;

      for (int j = 1; j <= n; j++) {
        bool temp = cur[j];
        if (p[j - 1] == '*') {
          cur[j] = cur[j - 2] ||
                   (i && cur[j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
        } else {
          cur[j] = i && pre && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        }

        pre = temp;
      }
    }

    return cur[n];
  }
};

// Solution2: dp
// T(n) = O()
// S(n) = O()
class Solution {
 public:
  bool isMatch(string s, string p) {
    int m = s.length();
    int n = p.length();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;

    for (int i = 0; i < m + 1; i++) {
      for (int j = 1; j < n + 1; j++) {
        if (p[j - 1] != '*') {
          dp[i][j] = i > 0 && dp[i - 1][j - 1] &&
                     (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        } else {
          dp[i][j] =
              dp[i][j - 2] || (i > 0 && dp[i - 1][j] &&
                               (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
        }
      }
    }

    return dp[m][n];
  }
};
