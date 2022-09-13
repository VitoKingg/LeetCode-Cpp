#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 0005 Longest Palindromic Substring (Medium)
 *
 * Given a string s, return the longest palindromic substring in s.
 *
 */
// two pointers
// Time:  O(n^2)
// Space: O(1)
class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.size() < 2) {
      return s;
    }

    int max_len = 0;
    int start_idx = 0;
    int n = s.size();
    int i = 0;
    while (i < n) {
      int r_ptr = i;
      int l_ptr = i;

      // find the middle of a palindrome
      while (r_ptr < n - 1 && s[r_ptr] == s[r_ptr + 1]) {
        ++r_ptr;
      }
      i = r_ptr + 1;

      // expand from the middle out
      while (r_ptr < n - 1 && l_ptr > 0 && s[r_ptr + 1] == s[l_ptr - 1]) {
        ++r_ptr;
        --l_ptr;
      }

      int new_len = r_ptr - l_ptr + 1;
      if (new_len > max_len) {
        start_idx = l_ptr;
        max_len = new_len;
      }
    }

    return s.substr(start_idx, max_len);
  }
};

// Time:  O(n)
// Space: O(n)
// Manacher's Algorithm.
class Solution {
 public:
  string longestPalindrome(string s) {
    // @ and $ signs are sentinels appended to each end to avoid bounds checking
    const string &t = join('@' + s + '$', '#');
    const int n = t.length();
    // t[i - max_extends[i]..i) ==
    // t[i + 1..i + max_extends[i]]
    vector<int> max_extends(n);
    int center = 0;

    for (int i = 1; i < n - 1; ++i) {
      const int right_boundary = center + max_extends[center];
      const int mirror_index = center - (i - center);
      max_extends[i] = right_boundary > i &&
                       min(right_boundary - i, max_extends[mirror_index]);

      // Attempt to expand palindrome centered at i
      while (t[i + 1 + max_extends[i]] == t[i - 1 - max_extends[i]]) {
        ++max_extends[i];
      }

      // If palindrome centered at i expand past right_boundary,
      // adjust center based on expanded palindrome.
      if (i + max_extends[i] > right_boundary) {
        center = i;
      }
    }

    // Find the max_extend and best_center
    int max_extend = 0;
    int best_center = -1;

    for (int i = 0; i < n; ++i)
      if (max_extends[i] > max_extend) {
        max_extend = max_extends[i];
        best_center = i;
      }

    const int l = (best_center - max_extend) / 2;
    const int r = (best_center + max_extend) / 2;
    return s.substr(l, r - l);
  }

 private:
  string join(const string &s, char c) {
    string joined;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
      joined += s[i];

      if (i != n - 1) {
        joined += c;
      }
    }

    return joined;
  }
};

// Dynamic Programming
// Time:  O(n^2)
// Space: O(n^2)
class Solution {
 public:
  string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int start = 0;
    int mx = 1;

    for (int j = 0; j < n; ++j) {
      for (int i = 0; i <= j; ++i) {
        if (j - i < 2) {
          dp[i][j] = s[i] == s[j];
        } else {
          dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
        }

        if (dp[i][j] && mx < j - i + 1) {
          start = i;
          mx = j - i + 1;
        }
      }
    }

    return s.substr(start, mx);
  }
};
