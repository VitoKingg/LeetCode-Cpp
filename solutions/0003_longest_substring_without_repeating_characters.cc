#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 0003 Longest Substring Without Repeating Characters (Medium)
 *
 *
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 *
 */

// using vector
// Time:  O(n)
// Space: O()
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int result = 0;
    vector<int> count(128);

    for (int l = 0, r = 0; r < s.size(); ++r) {
      ++count[s[r]];

      while (count[s[r]] > 1) {
        --count[s[l++]];
      }

      result = max(result, r - l + 1);
    }

    return result;
  }
};

// using unordered map
// Time:  O(n)
// Space: O()
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int result = 0;
    unordered_map<char, int> lookup;

    for (int left = 0, right = 0; right < s.size(); ++right) {
      if (lookup.count(s[right])) {
        left = max(left, lookup[s[right]] + 1);
      }

      lookup[s[right]] = right;
      result = max(result, right - left + 1);
    }

    return result;
  }
};

// using unordered set
// Time:  O(n)
// Space: O()
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> visited;
    int i = 0;
    int j = 0;
    int n = s.size();
    int result = 0;

    while (i < n && j < n) {
      if (visited.find(s[j]) == visited.end()) {
        visited.insert(s[j++]);
        result = max(result, j - i);
      } else {
        visited.erase(s[i++]);
      }
    }

    return result;
  }
};
