#include <cstddef>

// 计算Fibonacci数列的第n项，二分递归版
// T(n) = O(2^n)
long unsigned int FibonacciV1(int n) {
  return (n < 2) ? (long unsigned int)n
                 : FibonacciV1(n - 1) + FibonacciV1(n - 2);
}

// 计算Fibonacci数列的第n项，线性递归版
// T(n) = O(n), 需要O(n)规模的附加空间
long unsigned int FibonacciV2(int n, long unsigned int &prev) {
  if (n == 0) {
    prev = 1;
    return 0;
  } else {
    long unsigned int prevPrev;
    prev = FibonacciV2(n - 1, prevPrev);
    return prevPrev + prev;
  }
}

// 计算Fibonacci数列的第n项，动态规划迭代版
// T(n) = O(n), 仅需常数规模的附加空间
long unsigned int FibonacciV3(int n) {
  long unsigned int f = 0, g = 1;
  while (n-- > 0) {
    g += f;
    f = g - f;
  }
  return f;
}
