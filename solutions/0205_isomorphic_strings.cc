#include <string>
#include <vector>

using namespace std;

/**
 * @brief 0205 Isomorphic Strings (Easy)
 *
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings s and t are isomorphic if the characters in s can be replaced to
 * get t.
 *
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character, but a character may map to itself.
 *
 */

// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    vector<int> s2t(256);
    vector<int> t2s(256);

    for (int i = 0; i < s.length(); ++i) {
      if (s2t[s[i]] != t2s[t[i]]) {
        return false;
      }

      s2t[s[i]] = i + 1;
      t2s[t[i]] = i + 1;
    }

    return true;
  }
};
