/*
23. Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
*/

function mergeKLists(lists: Array<ListNode | null>): ListNode | null {
  return sort(0, lists.length - 1);

  function sort(l: number, r: number) {
    if (l > r) {
      return null;
    }

    if (l === r) {
      return lists[l];
    }

    const m = l + Math.trunc((r - l) / 2);

    return merge(sort(l, m), sort(m + 1, r));
  }

  function merge(l1: ListNode | null, l2: ListNode | null) {
    const dummy = new ListNode(0);
    let curr = dummy;

    for (; l1 && l2; curr = curr.next) {
      if (l1.val < l2.val) {
        curr.next = l1;
        l1 = l1.next;
      } else {
        curr.next = l2;
        l2 = l2.next;
      }
    }

    curr.next = l1 ? l1 : l2;
    return dummy.next;
  }
}
