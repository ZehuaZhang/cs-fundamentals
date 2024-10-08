/*
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.



Example 1:


Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
Example 2:


Input: root = [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.


Constraints:

The number of nodes in the tree is in the range [1, 100].
1 <= Node.val <= 1000
*/

import {Nullable} from './util/object';
import {TreeNode} from './data-structure/BinaryTree';
import {Queue} from './data-structure/Queue';

function isCompleteTree(root: Nullable<TreeNode>): boolean {
  const queue = new Queue();
  queue.push(root);

  while (queue.front() !== null) {
    const node = queue.pop();
    queue.push(node.left);
    queue.push(node.right);
  }
  while (queue.size && queue.front() === null) {
    queue.pop();
  }
  return queue.isEmpty();
}
