#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 0347 Top K Frequent Elements
 *
 * Given an integer array nums and an integer k, return the k most frequent
 * elements. You may return the answer in any order.
 *
 */

/**
 * @brief Bucket Sort
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */
class Solution {
 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> count;
    for (const int &num : nums) {
      ++count[num];
    }

    const int nums_len = nums.size();
    vector<vector<int>> bucket(nums_len + 1);
    for (const auto &kvp : count) {
      bucket[kvp.second].push_back(kvp.first);
    }

    vector<int> result;
    for (int i = nums_len; i > 0; --i) {
      for (const int num : bucket[i]) {
        result.push_back(num);
      }
      if (result.size() == k) {
        break;
      }
    }

    return result;
  }
};

/**
 * @brief using unordered_map and priority_queue
 *
 * T(n) = O(n log k)
 * S(n) = O(n)
 */
class Solution2 {
 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> counts;
    for (const auto &i : nums) {
      ++counts[i];
    }

    priority_queue<pair<int, int>> heap;
    for (const auto &kvp : counts) {
      heap.emplace(-kvp.second, kvp.first);
      if (heap.size() == k + 1) {
        heap.pop();
      }
    }

    vector<int> result;
    while (!heap.empty()) {
      result.emplace_back(heap.top().second);
      heap.pop();
    }
    // std::reverse, in algorithm header
    reverse(result.begin(), result.end());

    return result;
  }
};
