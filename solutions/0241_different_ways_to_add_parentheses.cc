#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 0241 Different Ways to Add Parentheses (Medium)
 *
 * Given a string expression of numbers and operators, return all possible
 * results from computing all the different possible ways to group numbers and
 * operators. You may return the answer in any order.
 *
 * The test cases are generated such that the output values fit in a 32-bit
 * integer and the number of different results does not exceed 104.
 *
 */
// Solution: Dynamic Programming
// Time:  O()
// Space: O()
class Solution {
 public:
  vector<int> diffWaysToCompute(string expression) {
    unordered_map<string, vector<int>> dp_map;
    return ComputeWithDP(expression, dp_map);
  }

  vector<int> ComputeWithDP(string expression,
                            unordered_map<string, vector<int>> &dp_map) {
    vector<int> result;
    int size = expression.size();

    for (int i = 0; i < size; i++) {
      char cur = expression[i];

      if (cur == '+' || cur == '-' || cur == '*') {
        // Split expression string into two parts and solve them recursively
        vector<int> result1, result2;
        string substr = expression.substr(0, i);

        // check if dp_map has the result for substr
        if (dp_map.find(substr) != dp_map.end()) {
          result1 = dp_map[substr];
        } else {
          result1 = ComputeWithDP(substr, dp_map);
        }

        substr = expression.substr(i + 1);
        if (dp_map.find(substr) != dp_map.end()) {
          result2 = dp_map[substr];
        } else {
          result2 = ComputeWithDP(substr, dp_map);
        }

        for (const auto &n1 : result1) {
          for (const auto &n2 : result2) {
            if (cur == '+') {
              result.push_back(n1 + n2);
            } else if (cur == '-') {
              result.push_back(n1 - n2);
            } else {
              result.push_back(n1 * n2);
            }
          }
        }
      }
    }

    // if the expression string contains only number
    if (result.empty()) {
      result.push_back(atoi(expression.c_str()));
    }

    // save to dp_map
    dp_map[expression] = result;
    return result;
  }
};

// Solution: Basic Recursive
// Time:  O(n * (C(2n, n) - C(2n, n - 1))), this is at least
// Space: O(C(2n, n) - C(2n, n - 1))
class Solution {
 public:
  vector<int> diffWaysToCompute(string expression) {
    vector<int> result;

    for (int i = 0; i < expression.length(); ++i) {
      const auto cur = expression[i];

      if (cur == '+' || cur == '-' || cur == '*') {
        vector<int> left = diffWaysToCompute(expression.substr(0, i));
        vector<int> right = diffWaysToCompute(expression.substr(i + 1));

        for (const auto &num1 : left) {
          for (const auto &num2 : right) {
            if (cur == '+') {
              result.emplace_back(num1 + num2);
            } else if (cur == '-') {
              result.emplace_back(num1 - num2);
            } else {
              result.emplace_back(num1 * num2);
            }
          }
        }
      }
    }

    // If the expression string contains only number.
    if (result.empty()) {
      result.emplace_back(stoi(expression));
    }

    return result;
  }
};
