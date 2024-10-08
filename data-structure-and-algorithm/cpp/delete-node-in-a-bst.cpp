// 450. Delete Node in a BST
// Difficulty: Medium

// Given a root node reference of a BST and a key, delete the node with the given key in the BST.
// Return the root node reference (possibly updated) of the BST.

// Basically, the deletion can be divided into two stages:

// Search for a node to remove.
// If the node is found, delete the node.
// Note: Time complexity should be O(height of tree).

// Example:

// root = [5,3,6,2,4,null,7]
// key = 3

//     5
//    / \
//   3   6
//  / \   \
// 2   4   7

// Given key to delete is 3. So we find the node with value 3 and delete it.

// One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

//     5
//    / \
//   4   6
//  /     \
// 2       7

// Another valid answer is [5,2,6,null,4,null,7].

//     5
//    / \
//   2   6
//    \   \
//     4   7

// Time:  O(h)
// Space: O(h)

 class Solution {
 public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) {
      return nullptr;
    } 
    if (root->val > key) {
      root->left = deleteNode(root->left, key);
    } else if (root->val < key) {
      root->right = deleteNode(root->right, key);
    } else {
      if (!root->left) {
        auto right = root->right;
        delete root;
        return right;
      } else if (!root->right) {
        auto left = root->left;
        delete root;
        return left;
      } else {
        auto successor = root->right;
        while (successor->left) {
          successor = successor->left;
        }
        root->val = successor->val;
        root->right = deleteNode(root->right, successor->val);
      }
    }
    return root;
  }
};