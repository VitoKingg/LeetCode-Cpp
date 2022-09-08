#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

/**
 * @brief 0053 Maximum Subarray (Easy)
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 *
 * A subarray is a contiguous part of an array.
 *
 */
// Solution：Kadane's Algorithm
// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  int maxSubArray(vector<int> &nums) {
    int curr_max = 0;
    int max_till_now = numeric_limits<int>::min();

    for (auto c : nums) {
      curr_max = max(c, curr_max + c);
      max_till_now = max(max_till_now, curr_max);
    }

    return max_till_now;
  }
};

// Solution：Dynamic Programming - Tabulation
// Time:  O(n)
// Space: O(n)
class Solution {
 public:
  int maxSubArray(vector<int> &nums) {
    vector<vector<int>> dp(2, vector<int>(size(nums)));
    dp[0][0] = dp[1][0] = nums[0];

    for (int i = 1; i < size(nums); i++) {
      dp[1][i] = max(nums[i], nums[i] + dp[1][i - 1]);
      dp[0][i] = max(dp[0][i - 1], dp[1][i]);
    }

    return dp[0].back();
  }
};

// Solution：Dynamic Programming - Tabulation, with max_element
// Time:  O(n)
// Space: O(n)
class Solution {
 public:
  int maxSubArray(vector<int> &nums) {
    vector<int> dp(nums);

    for (int i = 1; i < size(nums); i++) {
      dp[i] = max(nums[i], nums[i] + dp[i - 1]);
    }

    return *max_element(begin(dp), end(dp));
  }
};

// Solution：Brute-Force, Time Limit Exceeded
// Time:  O(n^2)
// Space: O(1)
class Solution {
 public:
  int maxSubArray(vector<int> &nums) {
    int n = size(nums);
    int result = numeric_limits<int>::min();

    for (int i = 0; i < n; i++) {
      for (int j = i, curr_sum = 0; j < n; j++) {
        curr_sum += nums[j];
        result = max(result, curr_sum);
      }
    }

    return result;
  }
};
