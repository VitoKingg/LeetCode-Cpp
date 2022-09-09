#include <random>

using namespace std;

/**
 * @brief 0382 Linked List Random Node (Medium)
 *
 * Given a singly linked list, return a random node's value from the linked
 * list. Each node must have the same probability of being chosen.
 *
 * Implement the Solution class:
 *
 *    - Solution(ListNode head) Initializes the object with the head of the
 * singly-linked list head.
 *    - int getRandom() Chooses a node randomly from the list and returns its
 * value. All the nodes of the list should be equally likely to be chosen.
 *
 */

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Time:  O(n)
// Space: O(1)
class Solution {
 public:
  Solution(ListNode *head) : head_node(head) {}

  int getRandom() {
    int result = 0;
    int length = 1;
    ListNode *p = head_node;

    while (p) {
      if (rand() % length == 0) {
        result = p->val;
      }
      length++;
      p = p->next;
    }

    return result;
  }

 private:
  // Note : head is guaranteed to be not null, so it contains at least one node.
  ListNode *head_node;
};
