#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 0139 Word Break (Medium)
 *
 * Given a string s and a dictionary of strings wordDict, return true if s can
 * be segmented into a space-separated sequence of one or more dictionary words.
 *
 * Note that the same word in the dictionary may be reused multiple times in the
 * segmentation.
 *
 * T(n) = O(n * l^2), l is the max length of the word
 * S(n) = O(n)
 */
class Solution {
 public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> words(begin(wordDict), end(wordDict));
    int n = s.size();
    vector<bool> dp(n + 1);
    dp[0] = true;

    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (dp[j] && words.count(s.substr(j, i - j))) {
          dp[i] = true;
          break;
        }
      }
    }

    return dp[n];
  }
};
