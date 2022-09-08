#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief 0300 Longest Increasing Subsequence (Medium)
 *
 * Given an integer array nums, return the length of the longest strictly
 * increasing subsequence.
 *
 * A subsequence is a sequence that can be derived from an array by deleting
 * some or no elements without changing the order of the remaining elements. For
 * example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
 *
 * T(n) = O()
 * S(n) = O()
 */

// Solution1: Binary search with STL.
// T(n) = O(nlogn)
// S(n) = O(n)
class Solution {
 public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
      auto it = lower_bound(result.begin(), result.end(), nums[i]);

      if (it == result.end()) {
        result.push_back(nums[i]);
      } else {
        *it = nums[i];
      }
    }

    return result.size();
  }
};

// Time:  O(n^2)
// Space: O(n)
// Traditional DP solution.
class Solution2 {
 public:
  int lengthOfLIS(vector<int> &nums) {
    const int n = nums.size();
    vector<int> dp(n, 1);
    int result = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[j] < nums[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }

      result = max(result, dp[i]);
    }

    return result;
  }
};
