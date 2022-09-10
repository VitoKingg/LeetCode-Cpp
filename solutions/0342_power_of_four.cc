using namespace std;

/**
 * @brief 0342 Power of Four (Easy)
 *
 * Given an integer n, return true if it is a power of four. Otherwise, return
 * false.
 *
 * An integer n is a power of four, if there exists an integer x such that n ==
 * 4x.
 *
 */
// Time:  O(1)
// Space: O(1)
class Solution {
 public:
  bool isPowerOfFour(int n) {
    // 0xaaaaaaaa is to get rid of those power of 2 but not power of 4
    // so that the single 1 bit always appears at the odd position
    // use 0xaaaaaaaa or 0b10101010101010101010101010101010
    return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
  }
};

// Solution:
// Time:  O(1)
// Space: O(1)
class Solution {
 public:
  bool isPowerOfFour(int n) {
    while (n && !(n & 0b11)) {
      n >>= 2;
    }

    return (n == 1);
  }
};

// Solution: Brute force
// Time:  O(1)
// Space: O(1)
class Solution {
 public:
  bool isPowerOfFour(int n) {
    while (n > 1) {
      if (n % 4) {
        return false;
      }

      n /= 4;
    }

    return n == 1;
  }
};
