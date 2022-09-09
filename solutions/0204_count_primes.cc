#include <cmath>
#include <vector>

using namespace std;

/**
 * @brief 0204 Count Primes (Easy)
 *
 * Given an integer n, return the number of prime numbers that are strictly less
 * than n.
 *
 */
// Time:  O(n * ?)
// Space: O(n)
class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 2) {
      return false;
    }

    vector<bool> primes(n, true);
    int cnt = n - 2;

    for (int i = 2; i < n; ++i) {
      if (primes[i]) {
        for (int j = 2 * i; j < n; j += i) {
          if (primes[j]) {
            primes[j] = false;
            --cnt;
          }
        }
      }
    }

    return cnt;
  }
};

// Time:  O(n/2 + n/3 + ... + n/p) = O(nlog(logn))
// Space: O(n)
class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 2) {
      return false;
    }

    vector<bool> primes(n, true);
    int i = 3;
    int sqrt_n = sqrt(n);
    int cnt = n / 2;
    while (i <= sqrt_n) {
      for (int j = i * i; j < n; j += 2 * i) {
        if (primes[j]) {
          --cnt;
          primes[j] = false;
        }
      }
      // 避免偶数和重复遍历
      do {
        i += 2;
      } while (i <= sqrt_n && !primes[i]);
    }

    return cnt;
  }
};
