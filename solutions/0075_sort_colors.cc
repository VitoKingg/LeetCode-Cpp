#include <vector>

using namespace std;

/**
 * @brief 0075 Sort Colors
 *
 * Given an array nums with n objects colored red, white, or blue, sort them
 * in-place so that objects of the same color are adjacent, with the colors in
 * the order red, white, and blue.
 *
 * We will use the integers 0, 1, and 2 to represent the color red, white, and
 * blue, respectively.
 *
 * You must solve this problem without using the library's sort function.
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

class Solution {
 public:
  void sortColors(vector<int> &nums) {
    static const int target = 1;
    for (int i = 0, left = 0, right = nums.size() - 1; i <= right;) {
      if (nums[i] > target) {
        swap(nums[i], nums[right--]);
      } else {
        if (nums[i] < target) {
          swap(nums[left++], nums[i]);
        }
        ++i;
      }
    }
  }
};
