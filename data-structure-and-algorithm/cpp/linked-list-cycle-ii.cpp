// 142. Linked List Cycle II
// Difficulty: Medium

// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

// Note: Do not modify the linked list.

// Follow up:
// Can you solve it without using extra space?

// Time:  O(n)
// Space: O(1)

class Solution {
public:
  ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head, *fast = head;

    while (fast && fast->next) {
      slow = slow->next, fast = fast->next->next;
      if (slow == fast) {
        slow = head;
        while (slow != fast) {
          slow = slow->next, fast = fast->next;
        }
        return slow;
      }
    }
    return nullptr;
  }
};
