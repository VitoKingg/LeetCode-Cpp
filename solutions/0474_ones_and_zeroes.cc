#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 0474 Ones and Zeroes (Medium)
 *
 * You are given an array of binary strings strs and two integers m and n.
 *
 * Return the size of the largest subset of strs such that there are at most m
 * 0's and n 1's in the subset.
 *
 * A set x is a subset of a set y if all elements of x are also elements of y.
 *
 * T(n) = O(s * m * n), s is the size of the array.
 * S(n) = O(m * n)
 *
 */
class Solution {
 public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (const string &s : strs) {
      // std::count defined in algorithm header
      const int zero_count = count(begin(s), end(s), '0');
      const int one_count = s.length() - zero_count;

      for (int i = m; i >= zero_count; --i) {
        for (int j = n; j >= one_count; --j) {
          // std::max defined in algorithm header
          dp[i][j] = max(dp[i][j], dp[i - zero_count][j - one_count] + 1);
        }
      }
    }

    return dp[m][n];
  }
};

class Solution2 {
 public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (const auto &str : strs) {
      int zero_count = 0;
      int one_count = 0;
      for (const auto &c : str) {
        if (c == '0') {
          ++zero_count;
        } else if (c == '1') {
          ++one_count;
        }
      }

      for (int i = m; i - zero_count >= 0; --i) {
        for (int j = n; j - one_count >= 0; --j) {
          // std::max defined in algorithm header
          dp[i][j] = max(dp[i][j], dp[i - zero_count][j - one_count] + 1);
        }
      }
    }

    return dp[m][n];
  }
};
