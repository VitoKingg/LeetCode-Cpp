#include <vector>

using namespace std;

/**
 * @brief 0540 Single Element in a Sorted Array
 *
 * You are given a sorted array consisting of only integers where every element
 * appears exactly twice, except for one element which appears exactly once.
 *
 * Return the single element that appears only once.
 *
 * Your solution must run in O(log n) time and O(1) space.
 *
 * T(n) = O(log n)
 * S(n) = O(1)
 */

class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;

    while (l < r) {
      int m = l + (r - l) / 2;

      // make m even if m is odd
      if (!(m % 2 == 0)) {
        --m;
      }
      if (nums[m] == nums[m + 1]) {
        l = m + 2;
      } else {
        r = m;
      }
    }

    return nums[l];
  }
};
