#include <numeric>
#include <vector>

using namespace std;

/**
 * @brief 0416 Partition Equal Subset Sum (Medium)
 *
 * Given a non-empty array nums containing only positive integers, find if the
 * array can be partitioned into two subsets such that the sum of elements in
 * both subsets is equal.
 *
 * T(n) = O(n * m), m is the sum of nums.
 * S(n) = O(m)
 *
 */
class Solution {
 public:
  bool canPartition(vector<int> &nums) {
    // std::accumulate defined in numeric header
    int sum = accumulate(begin(nums), end(nums), 0);

    if (sum % 2 != 0) {
      return false;
    }

    int n = sum / 2;
    vector<bool> dp(n + 1);
    dp[0] = true;

    for (int &v : nums) {
      for (int j = n; j >= v; --j) {
        dp[j] = dp[j] || dp[j - v];
      }
    }

    return dp[n];
  }
};

class Solution2 {
 public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(begin(nums), end(nums), 0);

    if (sum % 2 != 0) {
      return false;
    }

    int target = sum / 2;
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= target; ++j) {
        if (j < nums[i - 1]) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
        }
      }
    }

    return dp[n][target];
  }
};
