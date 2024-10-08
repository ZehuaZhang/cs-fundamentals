// 199. Binary Tree Right Side View
// Difficulty: Medium

// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// For example:
// Given the following binary tree,
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
// You should return [1, 3, 4].

// Time: O(n)
// Space: O(n)

class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> result;
    queue<TreeNode*> q;
    if (root) {
      q.push(root);
    }
    while (!q.empty()) {
      result.push_back(q.back()->val);
      int size = q.size();
      while (size--) {
        TreeNode* node = q.front(); q.pop();
        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
    }
    return result;
  }
};