using namespace std;

/**
 * @brief 0461 Hamming Distance (Easy)
 *
 * The Hamming distance between two integers is the number of positions at which
 * the corresponding bits are different.
 *
 * Given two integers x and y, return the Hamming distance between them.
 *
 */
// Solution: Brian-Kernighan
// Time:  O(K), where K is the hamming distance between given numbers. This
// assume XOR operation as O(1) Space: O(1)
class Solution {
 public:
  int hammingDistance(int x, int y) {
    int tmp = x ^ y;
    int result = 0;

    while (tmp) {
      ++result;
      tmp &= (tmp - 1);
    }

    return result;
  }
};

// Solution: XOR & count bits
// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  int hammingDistance(int x, int y) {
    int num = x ^ y;
    int result = 0;

    while (num) {
      // result += num % 2;
      result += num & 1;
      num >>= 1;
    }

    return result;
  }
};

// Solution: iterating & comparing each bit
// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  int hammingDistance(int x, int y) {
    int result = 0;

    while (x || y) {
      // result += (x % 2) != (y % 2);
      // result += (x & 1) ^ (y & 1);
      result += (x & 1) != (y & 1);
      x >>= 1;
      y >>= 1;
    }

    return result;
  }
};
