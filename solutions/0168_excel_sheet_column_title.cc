#include <algorithm>
#include <string>

using namespace std;

/**
 * @brief 0168 Excel Sheet Column Title (Easy)
 *
 * Given an integer columnNumber, return its corresponding column title as it
 * appears in an Excel sheet.
 *
 */
// Solution: Iterative
// Time:  O(logn)
// Space: O(1)
class Solution {
 public:
  string convertToTitle(int columnNumber) {
    string result;

    while (columnNumber) {
      result.push_back((columnNumber - 1) % 26 + 'A');
      columnNumber = (columnNumber - 1) / 26;
    }
    reverse(result.begin(), result.end());

    return result;
  }
};

// Solution: Recursive
// Time:  O((logn)^2)
// Space: O(logn)
class Solution {
 public:
  string convertToTitle(int columnNumber) {
    return columnNumber == 0
               ? ""
               : convertToTitle((columnNumber - 1) / 26) +
                     static_cast<char>((columnNumber - 1) % 26 + 'A');
  }
};
