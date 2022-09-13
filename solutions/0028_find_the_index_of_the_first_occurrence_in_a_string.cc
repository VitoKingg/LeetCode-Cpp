#include <string>
#include <vector>

using namespace std;

/**
 * @brief 0028 Find the Index of the First Occurrence in a String (Medium)
 *
 * Given two strings needle and haystack, return the index of the first
 * occurrence of needle in haystack, or -1 if needle is not part of haystack.
 *
 */

// using KMP algorithm
// Time:  O(n + k)
// Space: O(k)
class Solution {
 public:
  int strStr(string haystack, string needle) {
    int m = haystack.size();
    int n = needle.size();

    if (!n) {
      return 0;
    }

    vector<int> lps = kmpProcess(needle);
    for (int i = 0, j = 0; i < m;) {
      if (haystack[i] == needle[j]) {
        ++i;
        ++j;
      }

      if (j == n) {
        return i - j;
      }

      if (i < m && haystack[i] != needle[j]) {
        j ? j = lps[j - 1] : ++i;
      }
    }

    return -1;
  }

 private:
  vector<int> kmpProcess(string &needle) {
    int n = needle.size();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;

    while (i < n) {
      if (needle[i] == needle[len]) {
        lps[i] = ++len;
        ++i;
      } else if (len) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        ++i;
      }
    }

    return lps;
  }
};

// brute force
// Time:  O(n * k)
// Space: O(k)
class Solution {
 public:
  int strStr(string haystack, string needle) {
    const int m = haystack.size();
    const int n = needle.size();

    for (int i = 0; i < m - n + 1; ++i)
      if (haystack.substr(i, n) == needle) {
        return i;
      }

    return -1;
  }
};
