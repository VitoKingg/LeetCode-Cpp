#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

/**
 * @brief 0121 Best Time to Buy and Sell Stock (Easy)
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the ith day.
 *
 * You want to maximize your profit by choosing a single day to buy one stock
 * and choosing a different day in the future to sell that stock.
 *
 * Return the maximum profit you can achieve from this transaction. If you
 * cannot achieve any profit, return 0.
 *
 */

// Solution: with stl
// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int hold_one = numeric_limits<int>::min();
    int sell_one = numeric_limits<int>::min();

    for (const auto &price : prices) {
      hold_one = max(hold_one, -price);
      sell_one = max(sell_one, hold_one + price);
    }

    return sell_one;
  }
};
