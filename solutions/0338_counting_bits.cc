#include <vector>

using namespace std;

/**
 * @brief 0338 Counting Bits (Medium)
 *
 * Given an integer n, return an array result of length n + 1 such that for each
 * i (0 <= i <= n), result[i] is the number of 1's in the binary representation
 * of i.
 *
 */

// Time:  O(n)
// Space: O(n)
class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> result(n + 1);

    for (int i = 1; i <= n; ++i) {
      // Note: i&1 equals to i%2
      result[i] = result[i / 2] + (i & 1);
    }

    return result;
  }
};

// Time:  O(nlogn)
// Space: O(n)
class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> result;

    for (int i = 0; i <= n; i++) {
      int sum = 0;
      int num = i;

      while (num != 0) {
        sum += num % 2;
        num = num / 2;
      }

      result.push_back(sum);
    }

    return result;
  }
};
