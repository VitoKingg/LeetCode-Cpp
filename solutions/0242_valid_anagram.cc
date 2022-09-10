#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 0242 Valid Anagram (Easy)
 *
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 */

// normal approach
// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (size(s) != size(t)) {
      return false;
    }

    vector<int> cnt(26);
    for (int i = 0; i < size(s); ++i) {
      ++cnt[s[i] - 'a'];
      --cnt[t[i] - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
      if (cnt[i]) {
        return false;
      }
    }

    return true;
  }
};

// using hash table
// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (size(s) != size(t)) {
      return false;
    }

    unordered_map<char, int> cnt;
    for (int i = 0; i < size(s); ++i) {
      ++cnt[s[i]];
      --cnt[t[i]];
    }

    for (const auto &c : cnt) {
      if (c.second) {
        return false;
      }
    }

    return true;
  }
};

// using std::sort
// Time:  O(nlogn)
// Space: O(1)
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (size(s) != size(t)) {
      return false;
    }

    sort(begin(s), end(s));
    sort(begin(t), end(t));

    return s == t;
  }
};
