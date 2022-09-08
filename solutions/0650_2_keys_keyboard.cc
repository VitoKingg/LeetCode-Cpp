#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief 0650 2 Keys Keyboard (Medium)
 *
 * There is only one character 'A' on the screen of a notepad. You can perform
 * one of two operations on this notepad for each step:
 *
 *    - Copy All: You can copy all the characters present on the screen (a
 * partial copy is not allowed).
 *    - Paste: You can paste the characters which are copied last time.
 *
 * Given an integer n, return the minimum number of operations to get the
 * character 'A' exactly n times on the screen.
 *
 * T(n) = O()
 * S(n) = O()
 *
 */
// Solution1: normal loop
// T(n) = O(sqrt(n))
// S(n) = O(1)
class Solution {
 public:
  int minSteps(int n) {
    int result = 0;
    // the answer is the sum of prime factors
    for (int i = 2; i * i <= n; ++i) {
      while (n % i == 0) {
        result += i;
        n /= i;
      }
    }

    result += (n > 1) ? n : 0;

    return result;
  }
};

// Solution2: recursion
// T(n) = O()
// S(n) = O()
class Solution2 {
 public:
  int minSteps(int n) {
    if (n == 1) {
      return 0;
    }

    for (int i = 2; i < n; i++) {
      if (n % i == 0) {
        return i + minSteps(n / i);
      }
    }

    return n;
  }
};

// Solution3: dp
// T(n) = O(m * n)
// S(n) = O(n)
class Solution3 {
 public:
  int minSteps(int n) {
    vector<int> dp(n + 1);

    for (int i = 2; i < n + 1; i++) {
      dp[i] = i;
    }

    for (int i = 2; i <= n; i++) {
      for (int j = 2; j < i; j++) {
        if (i % j == 0) {
          dp[i] = min(dp[i], dp[i / j] + j);
        }
      }
    }

    return dp[n];
  }
};
