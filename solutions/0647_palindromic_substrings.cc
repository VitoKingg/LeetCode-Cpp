#include <string>

using namespace std;

/**
 * @brief 0647 Palindromic Substrings (Medium)
 *
 * Given a string s, return the number of palindromic substrings in it.
 *
 * A string is a palindrome when it reads the same backward as forward.
 *
 * A substring is a contiguous sequence of characters within the string.
 *
 */

// Time:  O(n^2)
// Space: O(1)
class Solution {
 public:
  int countSubstrings(string s) {
    int result = 0;
    int n = s.size();

    for (int k = 0; k < n * 2 - 1; ++k) {
      int i = k / 2;
      int j = (k + 1) / 2;

      while (~i && j < n && s[i] == s[j]) {
        ++result;
        --i;
        ++j;
      }
    }

    return result;
  }
};

class Solution {
 public:
  int countSubstrings(string s) {
    int result = 0;
    int n = s.size();

    for (int i = 0; i < n; i++) {
      int j = i - 1;
      int k = i;

      while (k < n - 1 && s[k] == s[k + 1]) {
        k++;
      }

      result += (k - j) * (k - j + 1) / 2;
      i = k++;

      while (~j && k < n && s[k] == s[j]) {
        ++k;
        --j;
        result++;
      }
    }

    return result;
  }
};
