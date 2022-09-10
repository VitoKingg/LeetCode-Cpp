#include <cmath>
#include <unordered_set>

using namespace std;

/**
 * @brief 0202 Happy Number (Easy)
 *
 * Write an algorithm to determine if a number n is happy.
 *
 * A happy number is a number defined by the following process:
 *
 *    - Starting with any positive integer, replace the number by the sum of the
 * squares of its digits.
 *    - Repeat the process until the number equals 1 (where it will stay), or it
 * loops endlessly in a cycle which does not include 1.
 *    - Those numbers for which this process ends in 1 are happy.
 *
 * Return true if n is a happy number, and false if not.
 *
 */
// Solution: using unordered_set
// Time:  O(nlogn)
// Space: O(n)
class Solution {
 public:
  bool isHappy(int n) {
    unordered_set<int> visited;

    while (n != 1 && !visited.count(n)) {
      visited.emplace(n);
      n = GetNextNumber(n);
    }

    return n == 1;
  }

  int GetNextNumber(int n) {
    int sum = 0;

    while (n) {
      sum += pow(n % 10, 2);
      n /= 10;
    }

    return sum;
  }
};

// Solution: Floyd's Cycle detection algorithm
// Time:  O(m + n)
// Space: O(1)
class Solution {
 public:
  bool isHappy(int n) {
    int slow = GetNextNumber(n);
    int fast = GetNextNumber(GetNextNumber(n));

    while (slow != fast) {
      slow = GetNextNumber(slow);
      fast = GetNextNumber(GetNextNumber(fast));
    }

    return slow == 1;
  }

 private:
  int GetNextNumber(int n) {
    int sum = 0;

    while (n) {
      sum += pow(n % 10, 2);
      n /= 10;
    }

    return sum;
  };
};
