#include <string>
#include <vector>

using namespace std;

/**
 * @brief 0524 Longest Word in Dictionary through Deleting
 *
 * Given a string s and a string array dictionary, return the longest string in
 * the dictionary that can be formed by deleting some of the given string
 * characters. If there is more than one possible result, return the longest
 * word with the smallest lexicographical order. If there is no possible result,
 * return the empty string.
 *
 * T(n) = O(n^2)
 * S(n) = O(1)
 */

class Solution {
 public:
  string findLongestWord(string s, vector<string> &d) {
    string answer;

    for (const string &word : d) {
      if (IsSubsequence(word, s) &&
          (word.length() > answer.length() ||
           (word.length() == answer.length() && word < answer))) {
        answer = word;
      }
    }

    return answer;
  }

 private:
  // return true if a is a subsequence of b
  bool IsSubsequence(const string &a, const string &b) {
    int i = 0;
    for (const char c : b) {
      if (i < a.length() && c == a[i]) {
        ++i;
      }
    }

    return i == a.length();
  };
};
