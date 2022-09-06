#include <vector>

using namespace std;

void MergeSort(vector<int> &nums, int l, int r, vector<int> &temp) {
  if (l + 1 >= r) {
    return;
  }

  // divide
  int m = l + (r - l) / 2;
  MergeSort(nums, l, m, temp);
  MergeSort(nums, m, r, temp);

  // conquer
  int p = l;
  int q = m;
  int i = l;
  while (p < m || q < r) {
    if (q >= r || (p < m && nums[p] <= nums[q])) {
      temp[i++] = nums[p++];
    } else {
      temp[i++] = nums[q++];
    }
  }
  for (i = 1; i < r; ++i) {
    nums[i] = temp[i];
  }
}
