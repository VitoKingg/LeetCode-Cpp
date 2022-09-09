using namespace std;

/**
 * @brief 0172 Factorial Trailing Zeroes (Medium)
 *
 * Given an integer n, return the number of trailing zeroes in n!.
 *
 * Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.
 *
 */
// Time:  O(logn)
// Space: O(1)
class Solution {
 public:
  int trailingZeroes(int n) {
    int result = 0;
    while (n > 0) {
      result += n / 5;
      n /= 5;
    }
    return result;
  }
};

// Time:  O(logn)
// Space: O(1)
class Solution {
 public:
  int trailingZeroes(int n) {
    int result = 0;
    for (int i = 5; i <= n; i *= 5) {
      result += n / i;
    }
    return result;
  }
};

// Time:  O()
// Space: O()
class Solution {
 public:
  int trailingZeroes(int n) {
    return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
  }
};
