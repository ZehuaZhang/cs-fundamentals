/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:


Input: root = [1,2]
Output: [2,1]
Example 5:


Input: root = [1,null,2]
Output: [1,2]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?
*/

function inorderTraversal(root) {
    const stack = [];
    const result = [];
    for (let node = root; stack.length || node;) {
        if (node) {
            stack.push(node);
            node = node.left;
        } else {
            node = stack.pop();
            result.push(node.val);
            node = node.right;
        }
    }
    return result;
}