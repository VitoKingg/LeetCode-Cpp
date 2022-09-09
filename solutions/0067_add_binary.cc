#include <algorithm>
#include <string>

using namespace std;

/**
 * @brief 0067 Add Binary (Easy)
 *
 * Given two binary strings a and b, return their sum as a binary string.
 *
 */
// Time:  O(max(M, N))
// Space: O(max(M, N))
class Solution {
 public:
  string addBinary(string a, string b) {
    string result;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry == 1) {
      if (i >= 0) {
        carry += a[i--] - '0';
      }

      if (j >= 0) {
        carry += b[j--] - '0';
      }

      // Note: `a = a + "xy"` is O(n) while `a += xy` is O(1) (amortized)
      // Since `a = a + "xy"` creates a copy of a, appends "xy" and then
      // assigns it back to a
      // `a += "xy"` just appends "xy" to a
      result += static_cast<char>(carry % 2 + '0');
      carry /= 2;
    }

    reverse(begin(result), end(result));
    return result;
  }
};
