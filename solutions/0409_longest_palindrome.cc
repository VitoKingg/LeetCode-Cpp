#include <algorithm>
#include <string>

using namespace std;

/**
 * @brief 0409 Longest Palindrome (Easy)
 *
 * Given a string s which consists of lowercase or uppercase letters, return the
 * length of the longest palindrome that can be built with those letters.
 *
 * Letters are case sensitive, for example, "Aa" is not considered a palindrome
 * here.
 *
 */
// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  int longestPalindrome(string s) {
    int odds = 0;

    for (char c = 'A'; c <= 'z'; ++c) {
      odds += count(cbegin(s), cend(s), c) & 1;
    }

    return s.size() - odds + (odds > 0);
  }
};

// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  int longestPalindrome(string s) {
    vector<int> counter(256);

    for (const auto &c : s) {
      ++counter[c];
    }

    int odds = 0;
    for (const auto &c : counter) {
      odds += c % 2;
    }

    return s.size() - odds + (odds > 0);
  }
};
