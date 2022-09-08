#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

/**
 * @brief 0343 Integer Break (Medium)
 *
 * Given an integer n, break it into the sum of k positive integers, where k >=
 * 2, and maximize the product of those integers.
 *
 * Return the maximum product you can get.
 *
 */
// Solution：using std::pow int cmath header
// Time:  O(logn)
// Space: O(1)
class Solution {
 public:
  int integerBreak(int n) {
    if (n < 4) {
      return n - 1;
    }

    int result = 0;
    if (n % 3 == 0) {
      result = pow(3, n / 3);
    } else if (n % 3 == 2) {
      result = pow(3, n / 3) * 2;
    } else {
      result = pow(3, n / 3 - 1) * 4;
    }

    return result;
  }
};

// Solution
// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  int integerBreak(int n) {
    if (n < 4) {
      return n - 1;
    }

    int ans = 1;
    while (n > 4) {
      n -= 3;
      ans *= 3;
    }
    ans *= n;

    return ans;
  }
};

// Solution：Dynamic Programming
// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  int integerBreak(int n) {
    vector<int> dp(n + 1);
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        dp[i] = max(max(dp[i], dp[i - j] * j), (i - j) * j);
      }
    }

    return dp[n];
  }
};
