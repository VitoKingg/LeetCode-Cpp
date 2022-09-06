#include <vector>

using namespace std;

/**
 * @brief 0547 Number of Provinces
 *
 * There are n cities. Some of them are connected, while some are not. If city a
 * is connected directly with city b, and city b is connected directly with city
 * c, then city a is connected indirectly with city c.
 *
 * A province is a group of directly or indirectly connected cities and no other
 * cities outside of the group.
 *
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the
 * ith city and the jth city are directly connected, and isConnected[i][j] = 0
 * otherwise.
 *
 * Return the total number of provinces.
 *
 * T(n) = O(n^2)
 * S(n) = O(n)
 */

class Solution {
 public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    int n = isConnected.size();
    int count = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        dfs(isConnected, i, visited);
        ++count;
      }
    }

    return count;
  }

 private:
  void dfs(vector<vector<int>> &isConnected, int i, vector<bool> &visited) {
    visited[i] = true;
    for (int j = 0; j < isConnected.size(); ++j) {
      if (!visited[j] && isConnected[i][j] == 1) {
        dfs(isConnected, j, visited);
      }
    }
  }
};
