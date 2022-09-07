#include <queue>
#include <vector>

using namespace std;

/**
 * @brief 0310 Minimum Height Trees (Medium)
 *
 * A tree is an undirected graph in which any two vertices are connected by
 * exactly one path. In other words, any connected graph without simple cycles
 * is a tree.
 *
 * Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges
 * where edges[i] = [ai, bi] indicates that there is an undirected edge between
 * the two nodes ai and bi in the tree, you can choose any node of the tree as
 * the root. When you select a node x as the root, the result tree has height h.
 * Among all possible rooted trees, those with minimum height (i.e. min(h))  are
 * called minimum height trees (MHTs).
 *
 * Return a list of all MHTs' root labels. You can return the answer in any
 * order.
 *
 * The height of a rooted tree is the number of edges on the longest downward
 * path between the root and a leaf.
 *
 */
// using BFS and Topological Sorting
// T(n) = O(V+E)
// S(n) = O(V)
class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);

    for (auto &e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
      indegree[e[0]]++;
      indegree[e[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (indegree[i] == 1) {
        q.push(i);
        indegree[i]--;
      }
    }

    vector<int> result;
    while (!q.empty()) {
      int s = q.size();
      result.clear();
      for (int i = 0; i < s; i++) {
        int curr = q.front();
        q.pop();
        result.push_back(curr);
        for (auto child : graph[curr]) {
          indegree[child]--;
          if (indegree[child] == 1) {
            q.push(child);
          }
        }
      }
    }

    if (n == 1) {
      result.push_back(0);
    }

    return result;
  }
};
