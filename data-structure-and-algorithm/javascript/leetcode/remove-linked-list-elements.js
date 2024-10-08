/*
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50
*/

function removeElements(head, val) {
    const dummy = new ListNode();
    dummy.next = head;
    for (let curr = head, prev = dummy; curr; curr = curr.next) {
        if (curr.val === val) {
            prev.next  = curr.next;
        } else {
            prev  = prev.next;
        }
    }
    return dummy.next;
}

function removeElementsDFS(head, val) {
    if (!head) {
        return null;
    }
    head.next = removeElements(head.next, val);
    return head.val === val ? head.next : head;
}