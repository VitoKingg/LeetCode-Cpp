using namespace std;

/**
 * @brief 0693 Binary Number with Alternating Bits (Easy)
 *
 * Given a positive integer, check whether it has alternating bits: namely, if
 * two adjacent bits will always have different values.
 *
 */

// one line approach
// Time:  O(1)
// Space: O(1)
class Solution {
 public:
  bool hasAlternatingBits(int n) {
    return !((n ^= n / 2) & static_cast<long>(n) + 1);
  }
};

// intuitive approach
class Solution {
 public:
  bool hasAlternatingBits(int n) {
    n ^= (n >> 1);

    return (n & (static_cast<long>(n) + 1)) == 0;
  }
};

// Time:  O(1)
// Space: O(1)
class Solution {
 public:
  bool hasAlternatingBits(int n) {
    int d = n & 1;
    while ((n & 1) == d) {
      d = 1 - d;
      n >>= 1;
    }
    return n == 0;
  }
};
