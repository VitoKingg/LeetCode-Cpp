// 数组求和 迭代版
// T(n) = O(n)
int SumArrayV1(int arr[], int n) {
  int sum = 0;
  for (int i = 0; i != n; ++i) {
    sum += arr[i];
  }
  return sum;
}

// 数组求和 线性递归版
// T(n) = O(n)
int SumArrayV2(int arr[], int n) {
  if (n < 1) {
    return 0;
  } else {
    return SumArrayV2(arr, n - 1) + arr[n - 1];
  }
}

// 数组求和 二分递归版
// T(n) = O(hi - lo + 1)
int SumArrayV3(int arr[], int low, int high) {
  if (low == high) {
    return arr[low];
  } else {
    int mid = (low + high) >> 1;
    return SumArrayV3(arr, low, mid) + SumArrayV3(arr, mid + 1, high);
  }
}
