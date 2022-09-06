#include <algorithm>
#include <queue>
#include <random>
#include <vector>

using namespace std;

/**
 * @brief 0215 Kth Largest Element in an Array
 *
 * Given an integer array nums and an integer k, return the kth largest element
 * in the array.
 *
 * Note that it is the kth largest element in the sorted order, not the kth
 * distinct element.
 *
 * You must solve it in O(n) time complexity.
 */

/**
 * @brief quicksort using fixed pivot
 *
 * T(n) = O(n) ~ O(n^2)
 * S(n) = O(1)
 */
class Solution {
 public:
  int findKthLargest(vector<int> &nums, int k) {
    int left = 0, right = nums.size() - 1, kth;
    while (true) {
      int idx = Partition(nums, left, right);
      if (idx == k - 1) {
        kth = nums[idx];
        break;
      }
      if (idx < k - 1) {
        left = idx + 1;
      } else {
        right = idx - 1;
      }
    }
    return kth;
  }

 private:
  int Partition(vector<int> &nums, int left, int right) {
    int pivot = nums[left];
    int l = left + 1;
    int r = right;

    while (l <= r) {
      if (nums[l] < pivot && nums[r] > pivot) {
        swap(nums[l++], nums[r--]);
      }
      if (nums[l] >= pivot) {
        l++;
      }
      if (nums[r] <= pivot) {
        r--;
      }
    }
    swap(nums[left], nums[r]);

    return r;
  }
};

/**
 * @brief quicksort using random pivot
 *
 * T(n) = O(n) ~ O(n^2)
 * S(n) = O(1)
 */
class Solution2 {
 public:
  int findKthLargest(vector<int> &nums, int k) {
    int left = 0;
    int right = nums.size() - 1;

    default_random_engine gen((random_device())());

    while (left <= right) {
      uniform_int_distribution<int> dis(left, right);
      int pivot_idx = dis(gen);
      int new_pivot_idx = PartitionAroundPivot(left, right, pivot_idx, &nums);

      if (new_pivot_idx == k - 1) {
        break;
      } else if (new_pivot_idx > k - 1) {
        right = new_pivot_idx - 1;
      } else {
        left = new_pivot_idx + 1;
      }
    }

    return nums[k - 1];
  }

  int PartitionAroundPivot(int left, int right, int pivot_idx,
                           vector<int> *nums) {
    auto &nums_ref = *nums;
    int pivot_value = nums_ref[pivot_idx];
    int new_pivot_idx = left;

    swap(nums_ref[pivot_idx], nums_ref[right]);

    for (int i = left; i < right; ++i) {
      if (nums_ref[i] > pivot_value) {
        swap(nums_ref[i], nums_ref[new_pivot_idx++]);
      }
    }
    swap(nums_ref[right], nums_ref[new_pivot_idx]);

    return new_pivot_idx;
  }
};

/**
 * @brief min-heap using std::priority_queue in queue header
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */
class Solution2 {
 public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int num : nums) {
      pq.push(num);
      if (pq.size() > k) {
        pq.pop();
      }
    }

    return pq.top();
  }
};

/**
 * @brief max-heap using std::priority_queue in queue header
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */
class Solution3 {
 public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int> pq(nums.begin(), nums.end());

    for (int i = 0; i < k - 1; i++) {
      pq.pop();
    }

    return pq.top();
  }
};

/**
 * @brief Using std::nth_element in algorithm header
 *
 * T(n) = O(n) ~ O(n^2), on average O(n)
 * S(n) = O(1)
 */
class Solution4 {
 public:
  int findKthLargest(vector<int> &nums, int k) {
    nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());

    return nums[k - 1];
  }
};

/**
 * @brief Using std::partial_sort in algorithm header
 *
 * T(n) = approximatedly O(n log m), where m is distance
 * S(n) = O(1)
 */
class Solution5 {
 public:
  int findKthLargest(vector<int> &nums, int k) {
    partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
    return nums[k - 1];
  }
};
