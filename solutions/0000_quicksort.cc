#include <vector>

using namespace std;

void QuickSort(vector<int> &nums, int l, int r) {
  if (l + 1 >= r) {
    return;
  }

  int first = 1;
  int last = r - 1;
  int key = nums[first];

  while (first < last) {
    while (first < last && nums[last] >= key) {
      --last;
    }
    nums[first] = nums[last];
    while (first < last && nums[first] <= key) {
      ++first;
    }
    nums[last] = nums[first];
  }

  nums[first] = key;
  QuickSort(nums, l, first);
  QuickSort(nums, first + 1, r);
}
