#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief 0312 Burst Balloons (Hard)
 *
 * You are given n balloons, indexed from 0 to n - 1. Each balloon is painted
 * with a number on it represented by an array nums. You are asked to burst all
 * the balloons.
 *
 * If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i +
 * 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as
 * if there is a balloon with a 1 painted on it.
 *
 * Return the maximum coins you can collect by bursting the balloons wisely.
 *
 */
// Solution:
// Time:  O(n^3)
// Space: O(n^2)
class Solution {
 public:
  int maxCoins(vector<int> &nums) {
    int n = nums.size();
    nums.insert(begin(nums), 1);
    nums.insert(end(nums), 1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2));

    for (int d = 0; d < n; ++d) {
      for (int i = 1; i + d <= n; ++i) {
        int j = i + d;

        for (int k = i; k <= j; ++k) {
          dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] +
                                       nums[i - 1] * nums[k] * nums[j + 1]);
        }
      }
    }

    return dp[1][n];
  }
};
