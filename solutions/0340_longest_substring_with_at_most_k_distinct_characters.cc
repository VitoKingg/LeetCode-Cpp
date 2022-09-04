#include <string>
#include <vector>

using namespace std;

/**
 * @brief 0340 Longest Substring with At Most K Distinct Characters
 *
 * Given a string s and an integer k, return the length of the longest substring
 * of s that contains at most k distinct characters.
 *
 * T(n) = O()
 * S(n) = O(1)
 */

class Solution {
 public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    int ans = 0;
    int distinct = 0;
    const int ASCII_LEN = 128;
    vector<int> count(ASCII_LEN);

    for (int l = 0, r = 0; r < s.length(); ++r) {
      if (++count[s[r]] == 1) {
        ++distinct;
      }

      while (distinct == k + 1) {
        if (--count[s[l++]] == 0) {
          --distinct;
        }
      }

      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
