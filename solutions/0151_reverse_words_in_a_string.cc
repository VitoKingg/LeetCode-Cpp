#include <algorithm>
#include <string>

using namespace std;

/**
 * @brief 0151 Reverse Words in a String
 *
 * Given an input string s, reverse the order of the words.
 *
 * A word is defined as a sequence of non-space characters. The words in s will
 * be separated by at least one space.
 *
 * Return a string of the words in reverse order concatenated by a single space.
 *
 * Note that s may contain leading or trailing spaces or multiple spaces between
 * two words. The returned string should only have a single space separating the
 * words. Do not include any extra spaces.
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

class Solution {
 public:
  string reverseWords(string s) {
    // reverse the whole string
    reverse(begin(s), end(s));

    // reverse each word
    reverseWords(s, s.length());

    // clean up spaces
    return cleanSpaces(s, s.length());
  }

 private:
  void reverseWords(string& s, int n) {
    int i = 0;
    int j = 0;

    while (i < n) {
      // skip spaces
      while (i < j || i < n && s[i] == ' ') {
        ++i;
      }

      // skip non spaces
      while (j < i || j < n && s[j] != ' ') {
        ++j;
      }

      // reverse the word
      reverse(begin(s) + i, begin(s) + j);
    }
  }

  // trim leading, trailing, and middle spaces
  string cleanSpaces(string& s, int n) {
    int i = 0;
    int j = 0;

    while (j < n) {
      // skip spaces
      while (j < n && s[j] == ' ') {
        ++j;
      }

      // keep non spaces
      while (j < n && s[j] != ' ') {
        s[i++] = s[j++];
      }

      // skip spaces
      while (j < n && s[j] == ' ') {
        ++j;
      }

      // keep only one space
      if (j < n) s[i++] = ' ';
    }

    return s.substr(0, i);
  }
};
