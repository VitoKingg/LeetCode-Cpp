#include <vector>

using namespace std;

/**
 * @brief 0167 Two Sum II - Input Array Is Sorted
 *
 * Given a 1-indexed array of integers numbers that is already sorted in
 * non-decreasing order, find two numbers such that they add up to a specific
 * target number. Let these two numbers be numbers[index1] and numbers[index2]
 * where 1 <= index1 < index2 <= numbers.length.
 *
 * Return the indices of the two numbers, index1 and index2, added by one as an
 * integer array [index1, index2] of length 2.
 *
 * The tests are generated such that there is exactly one solution. You may not
 * use the same element twice.
 *
 * Your solution must use only constant extra space.
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

class Solution {
 public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> result{-1, -1};
    int i = 0;
    int j = numbers.size() - 1;
    int sum = 0;
    while (i < j) {
      sum = numbers[i] + numbers[j];
      if (sum > target) {
        --j;
      } else if (sum < target) {
        ++i;
      } else {
        result[0] = i + 1;
        result[1] = j + 1;
        break;
      }
    }

    return result;
  }
};
