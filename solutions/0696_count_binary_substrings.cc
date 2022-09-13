#include <algorithm>
#include <string>

using namespace std;

/**
 * @brief 0696 Count Binary Substrings (Easy)
 *
 * Given a binary string s, return the number of non-empty substrings that have
 * the same number of 0's and 1's, and all the 0's and all the 1's in these
 * substrings are grouped consecutively.
 *
 * Substrings that occur multiple times are counted the number of times they
 * occur.
 *
 */

// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  int countBinarySubstrings(string s) {
    int result = 0;
    int prev = 0;
    int curr = 1;

    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == s[i - 1]) {
        ++curr;
      } else {
        result += min(prev, curr);
        prev = curr;
        curr = 1;
      }
    }

    result += min(prev, curr);

    return result;
  }
};
