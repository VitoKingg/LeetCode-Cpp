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
 * T(n) = O(n)
 * S(n) = O(n)
 */

class Solution {
 public:
  int candy(vector<int> &ratings) {
    int ratings_size = ratings.size();
    vector<int> candy_num(ratings_size, 1);

    for (int i = 1; i != ratings_size; ++i) {
      if (ratings[i - 1] < ratings[i]) {
        candy_num[i] = candy_num[i - 1] + 1;
      }
    }

    for (int i = ratings_size - 1; i != 0; --i) {
      if ((ratings[i - 1] > ratings[i]) && (candy_num[i - 1] <= candy_num[i])) {
        candy_num[i - 1] = candy_num[i] + 1;
      }
    }

    return accumulate(candy_num.begin(), candy_num.end(), 0);
  }
};
