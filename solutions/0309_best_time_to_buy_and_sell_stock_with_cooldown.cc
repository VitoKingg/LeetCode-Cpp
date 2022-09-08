#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

/**
 * @brief 0309 Best Time to Buy and Sell Stock with Cooldown (Medium)
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the ith day.
 *
 * Find the maximum profit you can achieve. You may complete as many
 * transactions as you like (i.e., buy one and sell one share of the stock
 * multiple times) with the following restrictions:
 *
 *    - After you sell your stock, you cannot buy stock on the next day (i.e.,
 * cooldown one day).
 *
 * Note: You may not engage in multiple transactions simultaneously (i.e., you
 * must sell the stock before you buy again).
 *
 */
// Solution
// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int sell = 0;
    int hold = numeric_limits<int>::min();
    int prev = 0;

    for (const int &price : prices) {
      const int cache = sell;
      sell = max(sell, hold + price);
      hold = max(hold, prev - price);
      prev = cache;
    }

    return sell;
  }
};
