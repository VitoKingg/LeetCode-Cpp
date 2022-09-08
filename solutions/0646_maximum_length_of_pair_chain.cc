#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

/**
 * @brief 0646 Maximum Length of Pair Chain (Medium)
 *
 * You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and
 * lefti < righti.
 *
 * A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can
 * be formed in this fashion.
 *
 * Return the length longest chain which can be formed.
 *
 * You do not need to use up all the given intervals. You can select pairs in
 * any order.
 *
 */
// Solution: Greedy
// Time:  O(nlogn)
// Space: O(1)
class Solution {
 public:
  int findLongestChain(vector<vector<int>> &pairs) {
    int result = 0;
    int prev = numeric_limits<int>::min();

    sort(begin(pairs), end(pairs),
         [](const auto &a, const auto &b) { return a[1] < b[1]; });

    for (const auto &pair : pairs)
      if (pair[0] > prev) {
        ++result;
        prev = pair[1];
      }

    return result;
  }
};

// Solution: Dynamic Programming
// Time:  O(n^2)
// Space: O(n)
class Solution {
 public:
  int findLongestChain(vector<vector<int>> &pairs) {
    int n = pairs.size();
    sort(pairs.begin(), pairs.end());
    vector<int> dp(n, 1);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (pairs[i][0] > pairs[j][1]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }

    return *max_element(dp.begin(), dp.end());
  }
};
