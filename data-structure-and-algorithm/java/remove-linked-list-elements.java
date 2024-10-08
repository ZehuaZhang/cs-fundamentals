/**
 * Remove Linked List Elements 
 * 
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 */

public class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        for (ListNode prev = dummy; head != null; head = head.next) {
            if (head.val == val) {
                prev.next = head.next;
            } else {
                prev = head;
            }
        }

        return dummy.next;
    }
}

public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
    }
}