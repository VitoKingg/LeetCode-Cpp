#include <vector>

using namespace std;

/**
 * @brief 0932 Beautiful Array (Medium)
 *
 * An array nums of length n is beautiful if:
 *
 *    - nums is a permutation of the integers in the range [1, n].
 *    - For every 0 <= i < j < n, there is no index k with i < k < j where 2 *
 * nums[k] == nums[i] + nums[j].
 *
 * Given the integer n, return any beautiful array nums of length n. There will
 * be at least one valid answer for the given n.
 *
 */
// Solution: Divide and Conquer
// Time:  O(nlogn)
// Space: O(n)
class Solution {
 public:
  vector<int> beautifulArray(int n) {
    vector<int> result;

    for (int i = 0; i < n; i++) {
      result.push_back(i + 1);
    }

    HelperSort(result, 0, n - 1, 1);

    return result;
  }

 private:
  int HelperPartition(vector<int> &v, int start, int end, int mask) {
    int j = start;
    for (int i = start; i <= end; i++) {
      if ((v[i] & mask) != 0) {
        swap(v[i], v[j]);
        j++;
      }
    }

    return j;
  }

  void HelperSort(vector<int> &v, int start, int end, int mask) {
    if (start >= end) {
      return;
    }

    int mid = HelperPartition(v, start, end, mask);
    HelperSort(v, start, mid - 1, mask * 2);
    HelperSort(v, mid, end, mask * 2);
  }
};

// Solution:
// Time:  O()
// Space: O()
class Solution {
 public:
  vector<int> beautifulArray(int n) {
    vector<int> result = {1};

    while (result.size() < n) {
      vector<int> tmp;

      for (const int &i : result) {
        if (i * 2 - 1 <= n) {
          tmp.push_back(i * 2 - 1);
        }
      }

      for (const int &i : result) {
        if (i * 2 <= n) {
          tmp.push_back(i * 2);
        }
      }

      result = tmp;
    }

    return result;
  }
};

// Solution: Recursion
// Time:  O()
// Space: O()
class Solution {
 public:
  vector<int> beautifulArray(int n) {
    if (n == 1) {
      return {1};
    }

    vector<int> even = beautifulArray(n / 2);
    vector<int> odd = beautifulArray(n - (n / 2));
    vector<int> result;

    for (const auto &i : even) {
      result.push_back(2 * i);
    }

    for (const auto &i : odd) {
      result.push_back((2 * i) - 1);
    }

    return result;
  }
};
