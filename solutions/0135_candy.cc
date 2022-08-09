#include <numeric>
#include <vector>

using namespace std;

/**
 * @brief 0135 Candy
 *
 * There are n children standing in a line. Each child is assigned a rating
 * value given in the integer array ratings.
 *
 * You are giving candies to these children subjected to the following
 * requirements:
 *
 *    Each child must have at least one candy.
 *
 *    Children with a higher rating get more candies than their neighbors.
 *
 * Return the minimum number of candies you need to have to distribute the
 * candies to the children.
 *
 */

class Solution {
 public:
  int candy(vector<int>& ratings) {
    int size = ratings.size();
    vector<int> num(size, 1);

    for (int i = 1; i != ratings.size(); ++i) {
      if (ratings[i - 1] < ratings[i]) {
        num[i] = num[i - 1] + 1;
      }
    }
    for (int i = ratings.size() - 1; i != 0; --i) {
      if ((ratings[i - 1] > ratings[i]) && (num[i - 1] <= num[i])) {
        num[i - 1] = num[i] + 1;
      }
    }

    return accumulate(num.begin(), num.end(), 0);
  }
};
