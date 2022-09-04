#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class LinkedList {
 public:
  // constructor
  LinkedList() { head = NULL; }

  // dectructor
  ~LinkedList() {}

  // member functions
  void InsertNode(int);
  void DeleteNode(int);
  void PrintLinkedList();

 private:
  // members
  ListNode *head;
};

// function to insert a new node
void LinkedList::InsertNode(int val) {
  ListNode *new_node = new ListNode(val);

  if (head == NULL) {
    head = new_node;
    return;
  }

  ListNode *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = new_node;
}

// function to delete the node at given position
void LinkedList::DeleteNode(int offset) {
  ListNode *temp1 = head, *temp2 = NULL;
  int list_len = 0;

  if (head == NULL) {
    std::cout << "List empty." << std::endl;
    return;
  }

  // get the length of the linked-list
  while (temp1 != NULL) {
    temp1 = temp1->next;
    ++list_len;
  }

  // check if the position to be deleted is less than
  // the length of the linked-list
  if (list_len < offset) {
    std::cout << "Index out of range" << std::endl;
    return;
  }

  temp1 = head;
  if (offset == 1) {
    head = head->next;
    delete temp1;
    return;
  }

  while (offset-- > 1) {
    temp2 = temp1;
    temp1 = temp1->next;
  }

  temp2->next = temp1->next;
  delete temp1;
}

// function to print the nodes of the linked list
void LinkedList::PrintLinkedList() {
  ListNode *temp = head;

  if (head == NULL) {
    std::cout << "List empty." << std::endl;
    return;
  }

  while (temp != NULL) {
    std::cout << temp->val << " ";
    temp = temp->next;
  }
}
