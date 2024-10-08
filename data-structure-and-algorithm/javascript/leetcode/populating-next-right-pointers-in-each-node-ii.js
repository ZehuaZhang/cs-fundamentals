/*
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
 

Example 1:



Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 

Constraints:

The number of nodes in the given tree is less than 6000.
-100 <= node.val <= 100
*/

function connect(root) {
    for (let curr = root, next = null; curr; curr = next, next = null) {
        for (let prev = null; curr; curr = curr.next) {
            if (!next) {
                next = curr.left ? curr.left : curr.right;
            }
            if (curr.left) {
                if (prev) {
                    prev.next = curr.left;
                }
                prev = curr.left;
            }
            if (curr.right) {
                if (prev) {
                    prev.next = curr.right;
                }
                prev = curr.right;
            }
        }
    }
    return root;
}