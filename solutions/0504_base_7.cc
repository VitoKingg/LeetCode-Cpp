#include <string>

using namespace std;

/**
 * @brief 0504 Base 7 (Easy)
 *
 * Given an integer num, return a string of its base 7 representation.
 *
 */
// Time:  O()
// Space: O()
class Solution {
 public:
  string convertToBase7(int num) {
    if (num < 0) {
      return string("-").append(convertToBase7(-num));
    }

    if (num < 7) {
      return to_string(num);
    }

    return convertToBase7(num / 7).append(to_string(num % 7));
  }
};

// Time:  O()
// Space: O()
class Solution {
 public:
  string convertToBase7(int num) {
    if (num < 0) {
      return "-" + convertToBase7(-num);
    }

    string result = "";
    while (num) {
      result = to_string(num % 7) + result;
      num /= 7;
    }

    return result.empty() ? "0" : result;
  }
};
