#include <vector>

using namespace std;

/**
 * @brief 0417 Pacific Atlantic Water Flow (Medium)
 *
 * There is an m x n rectangular island that borders both the Pacific Ocean and
 * Atlantic Ocean. The Pacific Ocean touches the island's left and top edges,
 * and the Atlantic Ocean touches the island's right and bottom edges.
 *
 * The island is partitioned into a grid of square cells. You are given an m x n
 * integer matrix heights where heights[r][c] represents the height above sea
 * level of the cell at coordinate (r, c).
 *
 * The island receives a lot of rain, and the rain water can flow to neighboring
 * cells directly north, south, east, and west if the neighboring cell's height
 * is less than or equal to the current cell's height. Water can flow from any
 * cell adjacent to an ocean into the ocean.
 *
 * Return a 2D list of grid coordinates result where result[i] = [ri, ci]
 * denotes that rain water can flow from cell (ri, ci) to both the Pacific and
 * Atlantic oceans.
 *
 * T(n) = O(m * n)
 * S(n) = O(m * n)
 */
class Solution {
 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    const int m = heights.size();
    const int n = heights[0].size();
    vector<vector<int>> result;
    vector<vector<bool>> can_reach_p(m, vector<bool>(n));
    vector<vector<bool>> can_reach_a(m, vector<bool>(n));

    for (int i = 0; i < m; ++i) {
      dfs(heights, i, 0, can_reach_p);
      dfs(heights, i, n - 1, can_reach_a);
    }

    for (int j = 0; j < n; ++j) {
      dfs(heights, 0, j, can_reach_p);
      dfs(heights, m - 1, j, can_reach_a);
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (can_reach_p[i][j] && can_reach_a[i][j]) {
          result.push_back({i, j});
        }
      }
    }

    return result;
  }

 private:
  void dfs(const vector<vector<int>> &heights, int i, int j,
           vector<vector<bool>> &can_reach, int h = 0) {
    if (i < 0 || i == heights.size() || j < 0 || j == heights[0].size()) {
      return;
    }
    if (can_reach[i][j] || heights[i][j] < h) {
      return;
    }

    can_reach[i][j] = true;
    dfs(heights, i + 1, j, can_reach, heights[i][j]);
    dfs(heights, i - 1, j, can_reach, heights[i][j]);
    dfs(heights, i, j + 1, can_reach, heights[i][j]);
    dfs(heights, i, j - 1, can_reach, heights[i][j]);
  }
};
