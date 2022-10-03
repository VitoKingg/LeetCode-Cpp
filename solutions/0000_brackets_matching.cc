#include <stack>

// 括号匹配
bool paren(const char expr[], int low, int high) {
  std::stack<char> s;
  for (int i = low; i != high; ++i) {
    switch (expr[i]) {
      case '(':
      case '[':
      case '{':
        s.push(expr[i]);
        break;
      case ')':
        if (s.empty() || s.top() != '(') {
          return false;
        }
        s.pop();
        break;
      case ']':
        if (s.empty() || s.top() != '[') {
          return false;
        }
        s.pop();
        break;
      case '}':
        if (s.empty() || s.top() != '{') {
          return false;
        }
        s.pop();
        break;
      default:
        break;
    }
  }

  return s.empty();
}
