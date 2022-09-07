#include <vector>

using namespace std;

/**
 * @brief 0198 House Robber (Easy)
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping you
 * from robbing each of them is that adjacent houses have security systems
 * connected and it will automatically contact the police if two adjacent houses
 * were broken into on the same night.
 *
 * Given an integer array nums representing the amount of money of each house,
 * return the maximum amount of money you can rob tonight without alerting the
 * police.
 *
 * T(n) = O(n)
 * S(n) = O(1)
 *
 */
class Solution {
 public:
  int rob(vector<int> &nums) {
    int prev2 = 0, prev1 = 0, cur = 0;
    for (const auto &i : nums) {
      cur = max(prev1, i + prev2);
      prev2 = prev1;
      prev1 = cur;
    }
    return cur;
  }
};
