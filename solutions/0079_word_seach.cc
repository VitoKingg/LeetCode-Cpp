#include <string>
#include <vector>

using namespace std;

/**
 * @brief 0079 Word Search (Medium)
 *
 * Given an m x n grid of characters board and a string word, return true if
 * word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 *
 * T(n) = O(m * n * 4 * 3^(l - 1)) ~= O(m * n * 3^l), l is the length of the
 * word
 * S(n) = O(l)
 */
class Solution {
 public:
  bool exist(vector<vector<char>> &board, string word) {
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (dfs(board, word, i, j, 0)) {
          return true;
        }
      }
    }

    return false;
  }

 private:
  bool dfs(vector<vector<char>> &board, const string &word, int i, int j,
           int s) {
    if (i < 0 || i == board.size() || j < 0 || j == board[0].size()) {
      return false;
    }

    if (board[i][j] != word[s] || board[i][j] == '*') {
      return false;
    }

    if (s == word.length() - 1) {
      return true;
    }

    const char cache = board[i][j];
    board[i][j] = '*';
    const bool is_exist = dfs(board, word, i + 1, j, s + 1) ||
                          dfs(board, word, i - 1, j, s + 1) ||
                          dfs(board, word, i, j + 1, s + 1) ||
                          dfs(board, word, i, j - 1, s + 1);
    board[i][j] = cache;

    return is_exist;
  }
};
