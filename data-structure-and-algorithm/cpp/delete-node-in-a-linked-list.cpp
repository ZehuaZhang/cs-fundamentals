// 237. Delete Node in a Linked List
// Difficulty: Easy

// Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

// Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, 
// the linked list should become 1 -> 2 -> 4 after calling your function.

// Time:  O(1)
// Space: O(1)

class Solution {
public:
  void deleteNode(ListNode* node) {
    if (!node) {
      return;
    }
    ListNode* next = node->next;
    node->val = next->val;
    node->next = next->next;
    delete next;
  }
};
