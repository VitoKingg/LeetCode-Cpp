#include <string>

using namespace std;

/**
 * @brief 0680 Valid Palindrome II
 *
 * Given a string s, return true if the s can be palindrome after deleting at
 * most one character from it.
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

class Solution {
 public:
  bool validPalindrome(string s) {
    for (int l = 0, r = s.length() - 1; l < r; ++l, --r) {
      if (s[l] != s[r]) {
        return validPalindrome(s, l + 1, r) || validPalindrome(s, l, r - 1);
      }
    }

    return true;
  }

  bool validPalindrome(const string &s, int l, int r) {
    while (l < r) {
      if (s[l++] != s[r--]) {
        return false;
      }
    }

    return true;
  }
};
