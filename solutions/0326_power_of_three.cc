#include <cmath>

using namespace std;

/**
 * @brief 0326 Power of Three (Easy)
 *
 * Given an integer n, return true if it is a power of three. Otherwise, return
 * false.
 *
 * An integer n is a power of three, if there exists an integer x such that n ==
 * 3x.
 *
 */
// Solution: 3^19 = 1162261467 is the highest power in Integer Range
// Time:  O(1)
// Space: O(1)
class Solution {
 public:
  bool isPowerOfThree(int n) {
    // return n > 0 && 1162261467 % n == 0;
    return n > 0 && static_cast<int>(pow(3, 19)) % n == 0;
  }
};

// Solution: Loops
// Time:  O(log3(n))
// Space: O(1)
class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n > 1) {
      while (n % 3 == 0) {
        n /= 3;
      }
    }

    return n == 1;
  }
};

// Solution:
// Time:  O()
// Space: O(1)
class Solution {
 public:
  bool isPowerOfThree(int n) { return fmod(log10(n) / log10(3), 1) == 0; }
};

// Solution: Recursion
// Time:  O(log3(n))
// Space: O(log3(n))
class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n <= 1) {
      return n == 1;
    }

    return n % 3 == 0 && isPowerOfThree(n / 3);
  }
};
