#include <numeric>
#include <vector>

using namespace std;

/**
 * @brief 0268 Missing Number (Easy)
 *
 * Given an array nums containing n distinct numbers in the range [0, n], return
 * the only number in the range that is missing from the array.
 *
 */
// bit manipulation
// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  int missingNumber(vector<int> &nums) {
    int n = nums.size();
    int result = n;

    for (int i = 0; i < n; ++i) {
      result ^= (i ^ nums[i]);
    }

    return result;
  }
};

// intuitive approach
// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  int missingNumber(vector<int> &nums) {
    int sum = 0;
    int n = nums.size();
    int total = n * (n + 1) / 2;

    for (const auto &num : nums) {
      sum += num;
    }

    return total - sum;
  }
};

// one line approach
// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  int missingNumber(vector<int> &nums) {
    return nums.size() * (nums.size() + 1) / 2 -
           accumulate(nums.begin(), nums.end(), 0);
  }
};
