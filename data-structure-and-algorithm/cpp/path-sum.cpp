// 112. Path Sum
// Difficulty: Easy

// Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
// such that adding up all the values along the path equals the given sum.

// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \      \
//         7    2      1
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

// Time : O(n)
// Space: O(n)

class Solution {
public:
  bool hasPathSum(TreeNode* root, int sum) {
    if (!root) {
      return false;
    }
    if (!root->left && !root->right) {
      return sum == root->val;
    }
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
  }
};
