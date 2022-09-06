#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 0451 Sort Characters By Frequency
 *
 * Given a string s, sort it in decreasing order based on the frequency of the
 * characters. The frequency of a character is the number of times it appears in
 * the string.
 *
 * Return the sorted string. If there are multiple answers, return any of them.
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */
class Solution {
 public:
  string frequencySort(string s) {
    unordered_map<char, int> freq;
    for (const auto &c : s) {
      ++freq[c];
    }

    vector<string> buckets(s.size() + 1);
    for (const auto &kvp : freq) {
      buckets[kvp.second].push_back(kvp.first);
    }

    string result;
    for (int count = buckets.size() - 1; count >= 0; --count) {
      for (const auto &c : buckets[count]) {
        result += string(count, c);
      }
    }

    return result;
  }
};
