#include <vector>

using namespace std;

/**
 * @brief 0238 Product of Array Except Self (Medium)
 *
 * Given an integer array nums, return an array answer such that answer[i] is
 * equal to the product of all the elements of nums except nums[i].
 *
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 *
 * You must write an algorithm that runs in O(n) time and without using the
 * division operation.
 *
 */
// Solution: Left_product taken as variable and using Right_product array as ans
// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  vector<int> productExceptSelf(vector<int> &nums) {
    const int n = nums.size();
    vector<int> ans(n, 1);

    for (int i = 1; i < n; ++i) {
      ans[i] = ans[i - 1] * nums[i - 1];
    }

    int suffix = 1;
    for (int i = n - 1; i >= 0; --i) {
      ans[i] *= suffix;
      suffix *= nums[i];
    }

    return ans;
  }
};

// Solution: Maintaining a left_product and a right_product array
// Time:  O(n)
// Space: O(n)
class Solution {
 public:
  vector<int> productExceptSelf(vector<int> &nums) {
    const int n = nums.size();
    vector<int> ans(n);
    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);

    for (int i = 1; i < n; ++i) {
      prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    for (int i = n - 2; i >= 0; --i) {
      suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < n; ++i) {
      ans[i] = prefix[i] * suffix[i];
    }

    return ans;
  }
};

// Solution: Naive solution using nested loop
// Time Limit Exceed
// Time:  O(n^2)
// Space: O(1)
class Solution {
 public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n, 1);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) {
          continue;
        }
        ans[i] = ans[i] * nums[j];
      }
    }

    return ans;
  }
};
