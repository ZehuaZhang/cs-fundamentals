// 328. Odd Even Linked List
// Difficulty: Medium

// Given a singly linked list, group all odd nodes together followed by the even nodes. 
// Please note here we are talking about the node number and not the value in the nodes.

// You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

// Example:
// Given 1->2->3->4->5->NULL,
// return 1->3->5->2->4->NULL.

// Note:
// The relative order inside both the even and odd groups should remain as it was in the input. 
// The first node is considered odd, the second node even and so on ...

// Time:  O(n)
// Space: O(1)

class Solution {
public:
  ListNode* oddEvenList(ListNode* head) {
    if (!head) {
      return head;
    }
    for (ListNode* odd = head, *even = head->next; even && even->next; even = even->next, odd = odd->next) {
      ListNode* evenHead = odd->next;
      odd->next = even->next;
      even->next = even->next->next;
      odd->next->next = evenHead;
    }
    return head;
  }
};
