#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

/**
 * @brief 0136 Single Number (Easy)
 *
 * Given a non-empty array of integers nums, every element appears twice except
 * for one. Find that single one.
 *
 * You must implement a solution with a linear runtime complexity and use only
 * constant extra space.
 *
 */

// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  int singleNumber(vector<int> &nums) {
    int result = 0;

    for (const int &num : nums) {
      result ^= num;
    }

    return result;
  }
};

// Time:  O()
// Space: O(1)
class Solution {
 public:
  int singleNumber(vector<int> &nums) {
    return accumulate(nums.cbegin(), nums.cend(), 0, std::bit_xor<int>());
  }
};

// Time:  O(nlogn)
// Space: O(1)
class Solution {
 public:
  int singleNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); i += 2) {
      if (nums[i] != nums[i - 1]) {
        return nums[i - 1];
      }
    }

    return nums[nums.size() - 1];
  }
};
