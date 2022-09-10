using namespace std;

/**
 * @brief 0476 Number Complement (Easy)
 *
 * The complement of an integer is the integer you get when you flip all the 0's
 * to 1's and all the 1's to 0's in its binary representation.
 *
 *    - For example, The integer 5 is "101" in binary and its complement is
 * "010" which is the integer 2.
 *
 * Given an integer num, return its complement.
 *
 */

// flip bits from right to left
// Time:  O(log(num))
// Space: O(1)
class Solution {
 public:
  int findComplement(int num) {
    unsigned int i = 1;

    while (i <= num) {
      num ^= i;
      i <<= 1;
    }

    return num;
  }
};

// Time: O(log(num)) = O(1) as there are at most 32 bits to move
// Space: O(1)
class Solution {
 public:
  int findComplement(int num) {
    unsigned mask = ~0;

    while (num & mask) {
      mask <<= 1;
    }

    // return ~num & ~mask;
    return ~num ^ mask;
  }
};

// brute force
// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  int findComplement(int num) {
    int i = 31;
    while ((num & 1 << i) == 0) {
      // skip the left 0 bits till we reach the 1st set bit from left
      i--;
    }
    while (i >= 0) {
      // flip all bits by XORing with 1
      num ^= 1 << i--;
    }

    return num;
  }
};
