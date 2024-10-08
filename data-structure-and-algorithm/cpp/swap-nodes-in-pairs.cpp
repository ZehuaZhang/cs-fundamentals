// 24. Swap Nodes in Pairs
// Difficulty: Easy

// Given a linked list, swap every two adjacent nodes and return its head.

// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

// Time:  O(n)
// Space: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    ListNode dummy{0};
    dummy.next = head;
    for (ListNode* curr = &dummy; curr->next && curr->next->next;) {
      ListNode* nextOne = curr->next;
      ListNode* nextTwo = curr->next->next;

      curr->next = nextTwo;
      nextOne->next = nextTwo->next;
      nextTwo->next = nextOne;

      curr = nextOne;
    }
    return dummy.next;
  }
};
