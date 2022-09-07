#include <string>
#include <vector>

using namespace std;

/**
 * @brief 0257 Binary Tree Paths (Easy)
 *
 * Given the root of a binary tree, return all root-to-leaf paths in any order.
 *
 * A leaf is a node with no children.
 *
 * T(n) = O()
 * S(n) = O()
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> result;
    if (!root) {
      return result;
    }

    binaryTreePaths(result, root, to_string(root->val));

    return result;
  }

 private:
  void binaryTreePaths(vector<string> &result, TreeNode *root, string t) {
    if (!root->left && !root->right) {
      result.push_back(t);
      return;
    }

    if (root->left) {
      binaryTreePaths(result, root->left,
                      t + "->" + to_string(root->left->val));
    }

    if (root->right) {
      binaryTreePaths(result, root->right,
                      t + "->" + to_string(root->right->val));
    }
  }
};
