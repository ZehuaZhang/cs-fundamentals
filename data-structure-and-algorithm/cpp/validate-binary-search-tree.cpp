// 98. Validate Binary Search Tree
// Difficulty: Medium

// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
// Example 1:
//     2
//    / \
//   1   3
// Binary tree [2,1,3], return true.
// Example 2:
//     1
//    / \
//   2   3
// Binary tree [1,2,3], return false.

// Time:  O(n)
// Space: O(h)

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, INT_MIN, INT_MAX);
	}

private:
	bool isValidBST(TreeNode* root, int lower, int upper) {
		if (!root) {
			return true;
		}
		if (root->val < lower || root->val > upper) {
			return false;
		}
		return isValidBST(root->left, lower, root->val) && isValidBST(root->right, root->val, upper);
  }
};