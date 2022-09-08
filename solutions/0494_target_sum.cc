#include <numeric>
#include <vector>

using namespace std;

/**
 * @brief 0494 Target Sum (Medium)
 *
 * You are given an integer array nums and an integer target.
 *
 * You want to build an expression out of nums by adding one of the symbols '+'
 * and '-' before each integer in nums and then concatenate all the integers.
 *
 *    - For example, if nums = [2, 1], you can add a '+' before 2 and a '-'
 * before 1 and concatenate them to build the expression "+2-1".
 *
 * Return the number of different expressions that you can build, which
 * evaluates to target.
 *
 */
// Solution: Dynamic Programming
// Time:  O(n * S)
// Space: O(S)
class Solution {
 public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int s = accumulate(begin(nums), end(nums), 0);

    if (s < target || (s - target) % 2 != 0) {
      return 0;
    }

    int n = (s - target) / 2;
    vector<int> dp(n + 1);
    dp[0] = 1;

    for (const auto &v : nums) {
      for (int j = n; j >= v; --j) {
        dp[j] += dp[j - v];
      }
    }

    return dp[n];
  }
};
