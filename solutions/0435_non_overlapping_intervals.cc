#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief 0435 Non-overlapping Intervals
 *
 * Given an array of intervals intervals where intervals[i] = [starti, endi],
 * return the minimum number of intervals you need to remove to make the rest of
 * the intervals non-overlapping.
 *
 * T(n) = O(nlogn)
 * S(n) = O(1)
 */

class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    if (intervals.empty()) {
      return 0;
    }

    sort(intervals.begin(), intervals.end(),
         [](const auto &a, const auto &b) { return a[1] < b[1]; });

    int removed = 0;
    int prev = intervals[0][1];
    for (int i = 1; i != intervals.size(); ++i) {
      if (intervals[i][0] < prev) {
        ++removed;
      } else {
        prev = intervals[i][1];
      }
    }

    return removed;
  }
};
