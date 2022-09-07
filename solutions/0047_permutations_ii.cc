#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief 0047 Permutations II (Medium)
 *
 * Given a collection of numbers, nums, that might contain duplicates, return
 * all possible unique permutations in any order.
 *
 * T(n) = O(n!)
 * S(n) = O(n)
 */
class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int> &num) {
    vector<vector<int>> result;

    sort(num.begin(), num.end());
    permute(num, 0, num.size(), result);

    return result;
  }

 private:
  void permute(vector<int> num, int i, int j, vector<vector<int>> &result) {
    if (i == j - 1) {
      result.push_back(num);
      return;
    }

    for (int k = i; k < j; k++) {
      if (i != k && num[i] == num[k]) {
        continue;
      }

      swap(num[i], num[k]);
      permute(num, i + 1, j, result);
    }
  }
};
