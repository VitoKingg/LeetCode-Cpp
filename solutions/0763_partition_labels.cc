#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 0763 Partition Labels
 *
 * You are given a string s. We want to partition the string into as many parts
 * as possible so that each letter appears in at most one part.
 *
 * Note that the partition is done so that after concatenating all the parts in
 * order, the resultant string should be s.
 *
 * Return a list of integers representing the size of these parts.
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

class Solution {
 public:
  vector<int> partitionLabels(string s) {
    vector<int> letter_rightmost_pos(26);
    int s_size = s.size();
    for (int i = 0; i < s_size; ++i) {
      letter_rightmost_pos[s[i] - 'a'] = i;
    }

    vector<int> result;
    for (int i = 0, left = 0, right = 0; i < s_size; ++i) {
      right = max(right, letter_rightmost_pos[s[i] - 'a']);
      if (i == right) {
        result.push_back(right - left + 1);
        left = right + 1;
      }
    }
    return result;
  }
};
