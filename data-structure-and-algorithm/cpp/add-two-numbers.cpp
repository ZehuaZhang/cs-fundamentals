// 2. Add Two Numbers
// Difficulty: Medium

// You are given two linked lists representing two non-negative numbers.
// The digits are stored in reverse order and each of their nodes contain a single digit.
// Add the two numbers and return it as a linked list.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

// Time:  O(n)
// Space: O(1)

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy{0};

    int carry = 0;
    for (ListNode* curr = &dummy; l1 || l2 || carry; curr = curr->next) {
      int a = l1 ? l1->val : 0;
      int b = l2 ? l2->val : 0;
      int val = carry + a + b;
      carry = val / 10;
      curr->next = new ListNode(val % 10);
      
      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
    }
    return dummy.next;
  }
};
