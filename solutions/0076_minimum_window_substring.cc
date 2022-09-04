#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 0076 Minimum Window Substring
 *
 * Given two strings s and t of lengths m and n respectively, return the minimum
 * window substring of s such that every character in t (including duplicates)
 * is included in the window. If there is no such substring, return the empty
 * string "".
 *
 * The testcases will be generated such that the answer is unique.
 *
 * A substring is a contiguous sequence of characters within the string.
 *
 * T(n) = O(n)
 * S(n) = O(k)
 */

class Solution {
 public:
  string minWindow(string s, string t) {
    const int ASCII_LEN = 128;
    vector<int> count(ASCII_LEN);

    int required = t.length();
    int best_left = -1;
    int min_len = s.length() + 1;

    for (const char c : t) {
      ++count[c];
    }

    for (int l = 0, r = 0; r < s.length(); ++r) {
      if (--count[s[r]] >= 0) {
        --required;
      }

      while (required == 0) {
        if (r - l + 1 < min_len) {
          best_left = l;
          min_len = r - l + 1;
        }

        if (++count[s[l++]] > 0) {
          ++required;
        }
      }
    }

    return best_left == -1 ? "" : s.substr(best_left, min_len);
  }
};

class Solution2 {
 public:
  string minWindow(string s, string t) {
    unordered_map<int, int> count;

    for (const auto &c : t) {
      ++count[c];
    }

    int remain = t.length();
    int left = -1, right = -1;
    for (int i = 0, j = 0; j < s.length(); ++j) {
      remain -= count[s[j]]-- > 0;

      if (remain) {
        continue;
      }

      while (count[s[i]] < 0) {
        ++count[s[i++]];
      }

      if (right == -1 || j - i + 1 < right - left + 1) {
        left = i;
        right = j;
      }
    }

    return left >= 0 ? s.substr(left, right - left + 1) : "";
  }
};
