// 54. Spiral Matrix
// Difficulty: Medium
// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

// For example,
// Given the following matrix:

// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// You should return [1,2,3,6,9,8,7,4,5].

// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    
    for (int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;
          left <= right && top <= bottom;
          ++left, --right, ++top, --bottom) {

      for (int j = left; j <= right; ++j) {
        res.emplace_back(matrix[top][j]);
      }
      for (int i = top + 1; i < bottom; ++i) {
        res.emplace_back(matrix[i][right]);
      }
      for (int j = right; top < bottom && j >= left; --j) {
        res.emplace_back(matrix[bottom][j]);
      }
      for (int i = bottom - 1; left < right && i > top; --i) {
        res.emplace_back(matrix[i][left]);
      }
    }
    return res;
  }
};