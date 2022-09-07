using namespace std;

/**
 * @brief 0070 Climbing Stairs (Easy)
 *
 * You are climbing a staircase. It takes n steps to reach the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 * T(n) = O(n)
 * S(n) = O(1)
 *
 */
class Solution {
 public:
  int climbStairs(int n) {
    int prev1 = 1;
    int prev2 = 1;

    for (int i = 2; i <= n; ++i) {
      const int dp = prev1 + prev2;
      prev2 = prev1;
      prev1 = dp;
    }

    return prev1;
  }
};
