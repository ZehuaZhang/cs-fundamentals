/*
A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(row, col) returns the element of the matrix at index (row, col) (0-indexed).
BinaryMatrix.dimensions() returns a list of 2 elements [rows, cols], which means the matrix is rows * cols.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you're given the binary matrix mat as input in the following four examples. You will not have access the binary matrix directly.

Example 1:
Input: mat = [[0,0],[1,1]]
Output: 0

Example 2:
Input: mat = [[0,0],[0,1]]
Output: 1

Example 3:
Input: mat = [[0,0],[0,0]]
Output: -1

Example 4:
Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
Output: 1
 

Constraints:
rows == mat.length
cols == mat[i].length
1 <= rows, cols <= 100
mat[i][j] is either 0 or 1.
mat[i] is sorted in a non-decreasing way.
*/

function leftMostColumnWithOne(matrix) {
    const [rows, cols] =  matrix.dimensions();
    let result = -1;
    for (let row = 0, col = cols - 1; row < rows && col >= 0;) {
        if (matrix.get(row, col) === 1) {
            result = col;
            --col;
        } else {
             ++row;
         }
    }
    return result;
}

function leftMostColumnWithOneBinarySearch(matrix) {
    const [rows, cols] =  matrix.dimensions();
    let result = Infinity;
    for (let i = 0; i < rows; ++i) {
        result = Math.min(result, binarySearch(matrix, i, cols));
    }
    return result === Infinity ? -1 : result;
}

function binarySearch(matrix, i, cols) {
    let left = 0, right = cols - 1;
    for (;left <= right;) {
        const mid = Math.trunc((right + low) / 2);
        if (matrix.get(row, mid) === 1) {
            right = mid + 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}