/**
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

/**
 * 
 * @param { ListNode } l1 
 * @param { ListNode } l2 
 * @returns { ListNode }
 */
function addTwoNumbers(l1, l2) {
    const dummy = new ListNode(0);

    let carry = 0;
    for (const curr = dummy; l1 || l2 || carry; curr = curr.next) {
        const a = l1 ? l1.value : 0;
        const b = l2 ? l2.value : 0;
        const sum = a + b + carry;
        carry = Math.trunc(sum / 10);
        curr.next = new ListNode(sum % 10);

        l1 = l1 ? l1.next : null;
        l2 = l2 ? l2.next : null;
    }

    return dummy.next;
}

class ListNode {
    constructor(value, next = null) {
        this.value = value;
        this.next = next;
    }
}