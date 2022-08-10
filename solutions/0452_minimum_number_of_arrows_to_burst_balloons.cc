#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief 0452 Minimum Number of Arrows to Burst Balloons
 *
 * There are some spherical balloons taped onto a flat wall that represents the
 * XY-plane. The balloons are represented as a 2D integer array points where
 * points[i] = [xstart, xend] denotes a balloon whose horizontal diameter
 * stretches between xstart and xend. You do not know the exact y-coordinates of
 * the balloons.
 *
 * Arrows can be shot up directly vertically (in the positive y-direction) from
 * different points along the x-axis. A balloon with xstart and xend is burst by
 * an arrow shot at x if xstart <= x <= xend. There is no limit to the number of
 * arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting
 * any balloons in its path.
 *
 * Given the array points, return the minimum number of arrows that must be shot
 * to burst all balloons.
 *
 * T(n) = O(nlogn)
 * S(n) = O(1)
 */

class Solution {
 public:
  int findMinArrowShots(vector<vector<int>> &points) {
    sort(begin(points), end(points),
         [](const auto &a, const auto &b) { return a[1] < b[1]; });

    int arrow_num = 1;
    int arrow_pos = points[0][1];

    for (int i = 1; i < points.size(); ++i)
      if (points[i][0] > arrow_pos) {
        arrow_pos = points[i][1];
        ++arrow_num;
      }

    return arrow_num;
  }
};
