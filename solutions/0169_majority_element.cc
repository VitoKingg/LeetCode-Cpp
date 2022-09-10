#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief 0169 Majority Element (Easy)
 *
 * Given an array nums of size n, return the majority element.
 *
 * The majority element is the element that appears more than ⌊n / 2⌋ times. You
 * may assume that the majority element always exists in the array.
 *
 */
// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  int majorityElement(vector<int> &nums) {
    int result;
    int counter = 0;

    for (const auto &num : nums) {
      if (counter == 0) {
        result = num;
      }
      counter += (num == result ? 1 : -1);
    }

    return result;
  }
};

// Solution: sorting
class Solution {
 public:
  int majorityElement(vector<int> &nums) {
    nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
    return nums[nums.size() / 2];
  }
};
