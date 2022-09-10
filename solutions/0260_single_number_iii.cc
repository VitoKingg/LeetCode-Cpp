#include <functional>
#include <numeric>
#include <vector>

using namespace std;

/**
 * @brief 0260 Single Number III (Medium)
 *
 * Given an integer array nums, in which exactly two elements appear only once
 * and all the other elements appear exactly twice. Find the two elements that
 * appear only once. You can return the answer in any order.
 *
 * You must write an algorithm that runs in linear runtime complexity and uses
 * only constant extra space.
 *
 */
// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  vector<int> singleNumber(vector<int> &nums) {
    long x_xor_y = 0;
    for (const auto &item : nums) {
      x_xor_y ^= item;
    }

    // long last_bit = x_xor_y & -x_xor_y;
    long last_bit = (x_xor_y & (x_xor_y - 1)) ^ x_xor_y;
    vector<int> result(2);
    for (const auto &item : nums) {
      if (item & last_bit) {
        result[0] ^= item;
      } else {
        result[1] ^= item;
      }
    }

    return result;
  }
};

// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  vector<int> singleNumber(vector<int> &nums) {
    // bit_xor defined in functional header
    long x_xor_y = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    // long last_bit = x_xor_y & -x_xor_y;
    long last_bit = (x_xor_y & (x_xor_y - 1)) ^ x_xor_y;

    vector<int> result(2);
    for (const auto &num : nums) {
      if ((num & last_bit) == 0) {
        result[0] ^= num;
      } else {
        result[1] ^= num;
      }
    }

    return result;
  }
};
