#include <algorithm>
#include <string>

using namespace std;

/**
 * @brief 0415 Add Strings (Easy)
 *
 * Given two non-negative integers, num1 and num2 represented as string, return
 * the sum of num1 and num2 as a string.
 *
 * You must solve the problem without using any built-in library for handling
 * large integers (such as BigInteger). You must also not convert the inputs to
 * integers directly.
 *
 */
// Time:  O(m + n)
// Space: O(1)
class Solution {
 public:
  string addStrings(string num1, string num2) {
    string result = "";
    int carry = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
      if (i >= 0) {
        carry += num1[i--] - '0';
      }

      if (j >= 0) {
        carry += num2[j--] - '0';
      }

      result += to_string(carry % 10);
      carry /= 10;
    }

    reverse(begin(result), end(result));
    return result;
  }
};
