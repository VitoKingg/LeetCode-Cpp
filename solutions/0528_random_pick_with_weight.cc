#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

/**
 * @brief 0528 Random Pick with Weight (Medium)
 *
 * You are given a 0-indexed array of positive integers w where w[i] describes
 * the weight of the ith index.
 *
 * You need to implement the function pickIndex(), which randomly picks an index
 * in the range [0, w.length - 1] (inclusive) and returns it. The probability of
 * picking an index i is w[i] / sum(w).
 *
 *    - For example, if w = [1, 3], the probability of picking index 0 is 1 / (1
 * + 3) = 0.25 (i.e., 25%), and the probability of picking index 1 is 3 / (1 +
 * 3) = 0.75 (i.e., 75%).
 *
 */

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */

// Time:  ctor: O(n)
//        pickIndex: O(logn)
// Space: O(n)
class Solution {
 public:
  Solution(vector<int> &w) : prefix(w.size()) {
    partial_sum(begin(w), end(w), begin(prefix));
  }

  int pickIndex() {
    const int target = rand() % prefix.back();
    return upper_bound(begin(prefix), end(prefix), target) - begin(prefix);
  }

 private:
  vector<int> prefix;
};

// Time:  ctor: O(n)
//        pickIndex: O(logn)
// Space: O(n)
class Solution {
 public:
  vector<int> s;

  Solution(vector<int> &w) {
    int n = w.size();
    s.resize(n + 1);
    for (int i = 0; i < n; ++i) {
      s[i + 1] = s[i] + w[i];
    }
  }

  int pickIndex() {
    int n = s.size();
    int x = 1 + rand() % s[n - 1];
    int left = 1, right = n - 1;

    while (left < right) {
      int mid = left + (right - left) / 2;
      if (s[mid] >= x) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left - 1;
  }
};
