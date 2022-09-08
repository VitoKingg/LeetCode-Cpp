#include <algorithm>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

/**
 * @brief 0188 Best Time to Buy and Sell Stock IV (Hard)
 *
 * You are given an integer array prices where prices[i] is the price of a given
 * stock on the ith day, and an integer k.
 *
 * Find the maximum profit you can achieve. You may complete at most k
 * transactions.
 *
 * Note: You may not engage in multiple transactions simultaneously (i.e., you
 * must sell the stock before you buy again).
 *
 */
// Solution1: dp
// Time:  O(k * n)
// Space: O(k)
class Solution {
 public:
  int maxProfit(int k, vector<int> &prices) {
    if (k >= prices.size() / 2) {
      int sell = 0;
      int hold = numeric_limits<int>::min();

      for (const int &price : prices) {
        sell = max(sell, hold + price);
        hold = max(hold, sell - price);
      }

      return sell;
    }

    vector<int> sell(k + 1);
    vector<int> hold(k + 1, numeric_limits<int>::min());

    for (const int &price : prices)
      for (int i = k; i > 0; --i) {
        sell[i] = max(sell[i], hold[i] + price);
        hold[i] = max(hold[i], sell[i - 1] - price);
      }

    return sell[k];
  }
};

// Solution2: using max heap and stack
// Time:  O(n + klogn)
// Space: O()
class Solution2 {
 public:
  int maxProfit(int k, vector<int> &prices) {
    vector<int> profits;
    // mono stack, where v is increasing and p is strictly decreasing
    vector<pair<int, int>> v_p_stk;

    // at most O(n) peaks, so v_p_stk and profits are both at most O(n) space
    for (int v = -1, p = -1; p + 1 < size(prices);) {
      for (v = p + 1; v + 1 < size(prices); ++v) {
        if (prices[v] < prices[v + 1]) {
          break;
        }
      }

      for (p = v; p + 1 < size(prices); ++p) {
        if (prices[p] > prices[p + 1]) {
          break;
        }
      }

      // not overlapped
      while (!empty(v_p_stk) && (prices[v_p_stk.back().first] > prices[v])) {
        const auto [last_v, last_p] = move(v_p_stk.back());
        v_p_stk.pop_back();
        // count [prices[last_v], prices[last_p]] interval
        profits.emplace_back(prices[last_p] - prices[last_v]);
      }

      // overlapped
      while (!empty(v_p_stk) && (prices[v_p_stk.back().second] <= prices[p])) {
        // prices[last_v] <= prices[v] <= prices[last_p] <= prices[p],
        // treat overlapped as [prices[v], prices[last_p]], [prices[last_v],
        // prices[p]] intervals due to invariant max profit
        const auto [last_v, last_p] = move(v_p_stk.back());
        v_p_stk.pop_back();
        // count [prices[v], prices[last_p]] interval
        profits.emplace_back(prices[last_p] - prices[v]);
        v = last_v;
      }

      // keep [prices[last_v], prices[p]] interval to check overlapped
      v_p_stk.emplace_back(v, p);
    }

    while (!empty(v_p_stk)) {
      const auto [last_v, last_p] = move(v_p_stk.back());
      v_p_stk.pop_back();
      // count [prices[last_v], prices[last_p]] interval
      profits.emplace_back(prices[last_p] - prices[last_v]);
    }

    if (k > size(profits)) {
      k = size(profits);
    } else {
      nth_element(begin(profits), begin(profits) + k - 1, end(profits),
                  greater<int>());
    }

    // top k profits of nonoverlapped intervals
    return accumulate(cbegin(profits), cbegin(profits) + k, 0);
  }
};
