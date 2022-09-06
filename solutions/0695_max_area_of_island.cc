#include <vector>

using namespace std;

/**
 * @brief 0075 Sort Colors
 *
 * Given an array nums with n objects colored red, white, or blue, sort them
 * in-place so that objects of the same color are adjacent, with the colors in
 * the order red, white, and blue.
 *
 * T(n) = O(m * n)
 * S(n) = O(m * n), the max depth of dfs may be m * n
 */

class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }

    int max_area = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1) {
          max_area = max(max_area, dfs(grid, i, j));
        }
      }
    }

    return max_area;
  }

 private:
  int dfs(vector<vector<int>> &grid, int i, int j) {
    if (grid[i][j] == 0) {
      return 0;
    }

    static const vector<int> direction{-1, 0, 1, 0, -1};
    grid[i][j] = 0;
    int x, y, area = 1;
    for (int k = 0; k < 4; ++k) {
      x = i + direction[k];
      y = j + direction[k + 1];

      if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
        area += dfs(grid, x, y);
      }
    }

    return area;
  }
};

class Solution2 {
 public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int max_area = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        max_area = max(max_area, dfs(grid, i, j));
      }
    }

    return max_area;
  }

 private:
  int dfs(vector<vector<int>> &grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
        grid[i][j] == 0) {
      return 0;
    }

    grid[i][j] = 0;

    return 1 + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) +
           dfs(grid, i, j - 1);
  }
};
