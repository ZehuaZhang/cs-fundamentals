/*
111. Minimum Depth of Binary Tree

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 2
Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
 

Constraints:

The number of nodes in the tree is in the range [0, 105].
-1000 <= Node.val <= 1000
*/

function minDepth(root: TreeNode | null): number {
  if (!root) {
    return 0;
  }

  const l = minDepth(root.left);
  const r = minDepth(root.right);

  return l && r ? Math.min(l, r) + 1 : l + r + 1;
}
