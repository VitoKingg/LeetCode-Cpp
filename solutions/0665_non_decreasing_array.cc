#include <vector>

using namespace std;

/**
 * @brief 0665 Non-decreasing Array
 *
 * Given an array nums with n integers, your task is to check if it could become
 * non-decreasing by modifying at most one element.
 *
 * We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for
 * every i (0-based) such that (0 <= i <= n - 2). T(n) = O(nlogn) S(n) = O(n)
 *
 * T(n) = O(n)
 * S(n) = O(1)
 *
 */

class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    int count = 0;
    for (int i = 1; i < nums.size() && count <= 1; i++) {
      if (nums[i - 1] > nums[i]) {
        count++;
        if (i - 2 < 0 || nums[i - 2] <= nums[i]) {
          nums[i - 1] = nums[i];
        } else {
          nums[i] = nums[i - 1];
        }
      }
    }

    return count <= 1;
  }
};
