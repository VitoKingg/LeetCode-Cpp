#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 0318 Maximum Product of Word Lengths (Medium)
 *
 * Given a string array words, return the maximum value of length(word[i]) *
 * length(word[j]) where the two words do not share common letters. If no such
 * two words exist, return 0.
 *
 */

// Solution: using bitmasks
// Time:  O(n^2)
// Space: O(n)
class Solution {
 public:
  int maxProduct(vector<string> &words) {
    int n = words.size();
    int result = 0;
    vector<int> mask(n);

    for (int i = 0; i < n; i++) {
      for (const auto &ch : words[i]) {
        mask[i] |= 1 << (ch - 'a');
      }

      for (int j = 0; j < i; j++) {
        if ((mask[i] & mask[j]) == 0) {
          result =
              max(result, static_cast<int>(words[i].size() * words[j].size()));
        }
      }
    }

    return result;
  }
};

// Time:  O(n^2)
// Space: O(n)
class Solution {
 public:
  int maxProduct(vector<string> &words) {
    int n = words.size();
    int result = 0;
    vector<int> mask(n);

    for (int i = 0; i < n; ++i) {
      for (const auto &ch : words[i]) {
        mask[i] |= 1 << (ch - 'a');
      }
    }

    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if ((mask[i] & mask[j]) == 0) {
          result =
              max(result, static_cast<int>(words[i].size() * words[j].size()));
        }
      }
    }

    return result;
  }
};
