#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief 0034 Find First and Last Position of Element in Sorted Array
 *
 * Given an array of integers nums sorted in non-decreasing order, find the
 * starting and ending position of a given target value.
 *
 * If target is not found in the array, return [-1, -1].
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 * T(n) = O(log n)
 * S(n) = O(1)
 */

class Solution {
 public:
  vector<int> searchRange(vector<int> &nums, int target) {
    const int l = lower_bound(begin(nums), end(nums), target) - begin(nums);
    if (l == nums.size() || nums[l] != target) {
      return {-1, -1};
    }
    const int r = upper_bound(begin(nums), end(nums), target) - begin(nums) - 1;
    return {l, r};
  }
};

class Solution2 {
 public:
  vector<int> searchRange(vector<int> &nums, int target) {
    const int l = lower_bound(nums, target);
    if (l == nums.size() || nums[l] != target) {
      return {-1, -1};
    }
    const int r = upper_bound(nums, target);
    return {l, r - 1};
  }

 private:
  int lower_bound(const vector<int> &nums, int target) {
    int left = 0, right = nums.size();

    while (left < right) {
      const auto mid = left + (right - left) / 2;

      if (nums[mid] >= target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }

  int upper_bound(const vector<int> &nums, int target) {
    int left = 0, right = nums.size();

    while (left < right) {
      const auto mid = left + (right - left) / 2;

      if (nums[mid] > target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }
};
