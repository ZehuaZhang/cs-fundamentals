// 19. Remove Nth Node From End of List
// Difficulty: Easy

// Given a linked list, remove the nth node from the end of list and return its head.

// For example,

//    Given linked list: 1->2->3->4->5, and n = 2.

//    After removing the second node from the end, the linked list becomes 1->2->3->5.

// Note:
// Given n will always be valid.
// Try to do this in one pass.

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
  ListNode* removeNthFromEnd(ListNode *head, int n) {
    ListNode dummy{0};
    dummy.next = head;

    ListNode* fast = &dummy;
    while (n--) {
      fast = fast->next;
    }

    ListNode* slow = &dummy;
    while (fast->next) {
      slow = slow->next;
      fast = fast->next;
    }

    ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    return dummy.next;
  }
};
