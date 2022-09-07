#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief 0040 Combination Sum II (Medium)
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 *
 * Each number in candidates may only be used once in the combination.
 *
 * Note: The solution set must not contain duplicate combinations.
 *
 * T(n) = O(n!)
 * S(n) = O(n)
 */
class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> result;
    vector<int> path;

    sort(begin(candidates), end(candidates));
    dfs(candidates, 0, target, path, result);

    return result;
  }

 private:
  void dfs(const vector<int> &candidates, int order, int target,
           vector<int> &path, vector<vector<int>> &result) {
    if (target < 0) {
      return;
    }

    if (target == 0) {
      result.push_back(path);
      return;
    }

    for (int i = order; i < candidates.size(); ++i) {
      if (i > order && candidates[i] == candidates[i - 1]) {
        continue;
      }

      path.push_back(candidates[i]);
      dfs(candidates, i + 1, target - candidates[i], path, result);
      path.pop_back();
    }
  }
};
