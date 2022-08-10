#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief 0406 Queue Reconstruction by Height
 *
 * You are given an array of people, people, which are the attributes of some
 * people in a queue (not necessarily in order). Each people[i] = [hi, ki]
 * represents the ith person of height hi with exactly ki other people in front
 * who have a height greater than or equal to hi.
 *
 * Reconstruct and return the queue that is represented by the input array
 * people. The returned queue should be formatted as an array queue, where
 * queue[j] = [hj, kj] is the attributes of the jth person in the queue
 * (queue[0] is the person at the front of the queue).
 *
 * T(n) = O(nlogn)
 * S(n) = O(n)
 */

class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    vector<vector<int>> result;

    sort(people.begin(), people.end(), [](const auto &a, const auto &b) {
      return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
    });

    for (const auto &p : people) {
      result.insert(result.begin() + p[1], p);
    }

    return result;
  }
};
