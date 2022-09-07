#include <vector>

using namespace std;

/**
 * @brief 0077 Combinations (Medium)
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * chosen from the range [1, n].
 *
 * You may return the answer in any order.
 *
 * T(n) = O(k * C(n, k))
 * S(n) = O(k)
 */
class Solution {
 public:
  vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > result;
    vector<int> path;

    dfs(n, k, 1, path, result);

    return result;
  }

 private:
  void dfs(int n, int k, int start, vector<int> &path,
           vector<vector<int> > &result) {
    if (k == 0) {
      result.push_back(path);
      return;
    }

    for (int i = start; i <= n; ++i) {
      path.push_back(i);
      dfs(n, k - 1, i + 1, path, result);
      path.pop_back();
    }
  }
};
