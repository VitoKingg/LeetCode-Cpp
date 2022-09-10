#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

/**
 * @brief 0462 Minimum Moves to Equal Array Elements II (Medium)
 *
 * Given an integer array nums of size n, return the minimum number of moves
 * required to make all array elements equal.
 *
 * In one move, you can increment or decrement an element of the array by 1.
 *
 * Test cases are designed so that the answer will fit in a 32-bit integer.
 *
 */
// Quick select solution.
// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  int minMoves2(vector<int> &nums) {
    const auto it = nums.begin() + nums.size() / 2;
    nth_element(nums.begin(), it, nums.end());
    const auto median = *it;
    int result = 0;

    for (const auto &num : nums) {
      result += abs(num - median);
    }

    return result;
  }
};

// Time:  O(nlogn)
// Space: O(1)
class Solution {
 public:
  int minMoves2(vector<int> &nums) {
    int n = nums.size();
    int result = 0;
    sort(nums.begin(), nums.end());
    int median = nums[n / 2];

    for (const auto &num : nums) {
      result += abs(num - median);
    }

    return result;
  }
};
