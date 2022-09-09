#include <random>
#include <vector>

using namespace std;

/**
 * @brief 0384 Shuffle an Array (Medium)
 *
 * Given an integer array nums, design an algorithm to randomly shuffle the
 * array. All permutations of the array should be equally likely as a result of
 * the shuffling.
 *
 * Implement the Solution class:
 *
 *    - Solution(int[] nums) Initializes the object with the integer array nums.
 *    - int[] reset() Resets the array to its original configuration and returns
 * it.
 *    - int[] shuffle() Returns a random shuffling of the array.
 *
 */

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

// Time:  O(n)
// Space: O(n)
class Solution {
 public:
  Solution(vector<int> &nums) : nums_(nums) {}

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() { return nums_; }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    vector<int> nums{nums_};
    default_random_engine seed((random_device())());

    for (int i = 0; i < nums.size(); ++i) {
      const int pos = uniform_int_distribution<int>{
          i, static_cast<int>(nums.size()) - 1}(seed);
      swap(nums[i], nums[pos]);
    }

    return nums;
  }

 private:
  const vector<int> nums_;
};
