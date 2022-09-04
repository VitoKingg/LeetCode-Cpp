#include <cmath>

using namespace std;

/**
 * @brief 0633 Sum of Square Numbers
 *
 * Given a non-negative integer c, decide whether there're two integers a and b
 * such that a2 + b2 = c.
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

class Solution {
 public:
  bool judgeSquareSum(int c) {
    unsigned long int l = 0;
    unsigned long int r = sqrt(c);

    while (l <= r) {
      unsigned long int sum = l * l + r * r;
      if (sum == c) {
        return true;
      }

      if (sum < c) {
        ++l;
      } else {
        --r;
      }
    }

    return false;
  }
};
