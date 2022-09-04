using namespace std;

/**
 * @brief 0069 Sqrt(x)
 *
 * Given a non-negative integer x, compute and return the square root of x.
 *
 * Since the return type is an integer, the decimal digits are truncated, and
 * only the integer part of the result is returned.
 *
 * Note: You are not allowed to use any built-in exponent function or operator,
 * such as pow(x, 0.5) or x ** 0.5.
 *
 * T(n) = O(logn)
 * S(n) = O(1)
 */

class Solution {
 public:
  int mySqrt(int x) {
    unsigned left = 1;
    unsigned right = x + 1u;

    while (left < right) {
      const unsigned mid = (left + right) / 2;

      if (mid > x / mid) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left - 1;
  }
};

// 牛顿迭代法
class Solution2 {
 public:
  int mySqrt(int x) {
    unsigned temp = x;

    while (temp * temp > x) {
      temp = (temp + x / temp) / 2;
    }

    return temp;
  }
};
