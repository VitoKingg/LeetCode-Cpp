#include <cctype>
#include <numeric>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 0227 Basic Calculator II (Medium)
 *
 * Given a string s which represents an expression, evaluate this expression and
 * return its value.
 *
 * The integer division should truncate toward zero.
 *
 * You may assume that the given expression is always valid. All intermediate
 * results will be in the range of [-231, 231 - 1].
 *
 * Note: You are not allowed to use any built-in function which evaluates
 * strings as mathematical expressions, such as eval().
 *
 */

// without stack
// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  int calculate(string s) {
    int result = 0;
    int prev = 0;
    int curr = 0;
    char sign = '+';

    for (int i = 0; i < s.size(); ++i) {
      const char c = s[i];
      if (isdigit(c)) {
        curr = curr * 10 + (c - '0');
      }

      if (!isdigit(c) && !isspace(c) || i == s.length() - 1) {
        if (sign == '+' || sign == '-') {
          result += prev;
          prev = sign == '+' ? curr : -curr;
        } else if (sign == '*') {
          prev *= curr;
        } else if (sign == '/') {
          prev /= curr;
        }

        sign = c;
        curr = 0;
      }
    }

    return result + prev;
  }
};

// using vector and this approach is faster than using stack.
// Time:  O(n)
// Space: O(n)
class Solution {
 public:
  int calculate(string s) {
    char sign = '+';
    int curr = 0;
    vector<int> stk;

    for (int i = 0; i < s.size(); ++i) {
      if (isdigit(s[i])) {
        curr = curr * 10 + (s[i] - '0');
      }

      if (i == s.size() - 1 || s[i] == '+' || s[i] == '-' || s[i] == '*' ||
          s[i] == '/') {
        if (sign == '+') {
          stk.push_back(curr);
        } else if (sign == '-') {
          stk.push_back(curr * (-1));
        } else if (sign == '*') {
          int num = stk.back();
          stk.pop_back();
          stk.push_back(num * curr);
        } else if (sign == '/') {
          int num = stk.back();
          stk.pop_back();
          stk.push_back(num / curr);
        }

        curr = 0;
        sign = s[i];
      }
    }

    return accumulate(begin(stk), end(stk), 0);
  }
};

// using stack
// Time:  O(n)
// Space: O(n)
class Solution {
 public:
  int calculate(string s) {
    s += '+';
    stack<int> stk;

    long long int result = 0;
    long long int curr = 0;
    char sign = '+';

    for (int i = 0; i < s.size(); i++) {
      if (isdigit(s[i])) {
        curr = curr * 10 + (s[i] - '0');
      } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
        if (sign == '+') {
          stk.push(curr);
        } else if (sign == '-') {
          stk.push(curr * (-1));
        } else if (sign == '*') {
          int num = stk.top();
          stk.pop();
          stk.push(num * curr);
        } else if (sign == '/') {
          int num = stk.top();
          stk.pop();
          stk.push(num / curr);
        }

        curr = 0;
        sign = s[i];
      }
    }

    while (stk.size()) {
      result += stk.top();
      stk.pop();
    }

    return result;
  }
};
