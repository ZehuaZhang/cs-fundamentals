// 103. Binary Tree Zigzag Level Order Traversal
// Difficulty: Medium

// Given a binary tree, return the zigzag level order traversal of its nodes values. 
// (ie, from left to right, then right to left for the next level and alternate between).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]

// Time : O(n)
// Space: O(n)

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    zigzagLevelOrder(root, 1, result);

    bool isLeftToRight = true;
    for (auto& element : result) {
      if (!isLeftToRight) {
        reverse(element.begin(), element.end());
      }
      isLeftToRight = !isLeftToRight;
    } 
    return result;
  }

private:
  void levelOrderBottom(TreeNode* root, size_t level, vector<vector<int>>& result) {
    if (!root) {
      return;
    }

    if (level > result.size()) {
      result.push_back(vector<int>());
    }
    result[level - 1].push_back(root->val);

    levelOrderBottom(root->left, level + 1, result);
    levelOrderBottom(root->right, level + 1, result);
  }
};


