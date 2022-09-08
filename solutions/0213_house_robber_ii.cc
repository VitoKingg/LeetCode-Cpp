#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief 0213 House Robber II (Medium)
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed. All houses at this place are
 * arranged in a circle. That means the first house is the neighbor of the last
 * one. Meanwhile, adjacent houses have a security system connected, and it will
 * automatically contact the police if two adjacent houses were broken into on
 * the same night.
 *
 * Given an integer array nums representing the amount of money of each house,
 * return the maximum amount of money you can rob tonight without alerting the
 * police.
 *
 */
// Solution
// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  int rob(vector<int> &nums) {
    int n = nums.size();

    if (n < 2) {
      return n ? nums[0] : 0;
    }

    return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
  }

 private:
  int robber(vector<int> &nums, int l, int r) {
    int pre = 0, cur = 0;

    for (int i = l; i <= r; i++) {
      int temp = max(pre + nums[i], cur);
      pre = cur;
      cur = temp;
    }

    return cur;
  }
};
