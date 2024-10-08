/*
61. Rotate List

Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
*/

function rotateRight(head: ListNode | null, k: number): ListNode | null {
  if (!head) {
    return head;
  }
  let len = 1;
  let curr = head;
  for (; curr.next; curr = curr.next, ++len);

  curr.next = head;
  k = len - (k % len);

  for (; k; --k, curr = curr.next);

  const prev = curr;
  curr = curr.next;
  prev.next = null;

  return curr;
}
