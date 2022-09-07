#include <numeric>
#include <vector>

using namespace std;

/**
 * @brief 0413 Arithmetic Slices (Medium)
 *
 * An integer array is called arithmetic if it consists of at least three
 * elements and if the difference between any two consecutive elements is the
 * same.
 *
 *    - For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic
 * sequences.
 *
 * Given an integer array nums, return the number of arithmetic subarrays of
 * nums.
 *
 * A subarray is a contiguous subsequence of the array.
 *
 * T(n) = O(n)
 * S(n) = O(1)
 *
 */
class Solution {
 public:
  int numberOfArithmeticSlices(vector<int> &nums) {
    const int n = nums.size();
    if (n < 3) {
      return 0;
    }

    vector<int> dp(n);

    for (int i = 2; i < n; ++i) {
      if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
        dp[i] = dp[i - 1] + 1;
      }
    }

    // std::accumulate in numeric header
    return accumulate(begin(dp), end(dp), 0);
  }
};

class Solution2 {
 public:
  int numberOfArithmeticSlices(vector<int> &nums) {
    int result = 0;
    int dp = 0;

    for (int i = 2; i < nums.size(); ++i) {
      if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
        result += ++dp;
      } else {
        dp = 0;
      }
    }

    return result;
  }
};
