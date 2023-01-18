/*
240. Search a 2D Matrix II
Difficulty: Medium

Write an efficient algorithm that searches for a value in an m x n matrix.
This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.

Time:  O(m + n)
Space: O(1)
*/

function searchMatrix2(matrix: number[][], target: number): boolean {
  const [rows, cols] = [matrix.length, matrix[0].length];

  for (let i = 0, j = cols - 1; i < rows && j >= 0; ) {
    if (matrix[i][j] === target) {
      return true;
    } else if (matrix[i][j] > target) {
      --j;
    } else {
      ++i;
    }
  }
  return false;
}
