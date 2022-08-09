#include <numeric>
#include <vector>

using namespace std;

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
