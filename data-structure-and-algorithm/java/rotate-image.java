/**
 * Rotate Image
 * 
 * You are given an n x n 2D matrix representing an image.
 * 
 * Rotate the image by 90 degrees (clockwise).
 * 
 * Note:
 * 
 * You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
 * 
 * Example 1:
 * 
 * Given input matrix = 
 * [
 *   [1,2,3],
 *   [4,5,6],
 *   [7,8,9]
 * ],
 * 
 * rotate the input matrix in-place such that it becomes:
 * [
 *   [7,4,1],
 *   [8,5,2],
 *   [9,6,3]
 * ]
 * Example 2:
 * 
 * Given input matrix =
 * [
 *   [ 5, 1, 9,11],
 *   [ 2, 4, 8,10],
 *   [13, 3, 6, 7],
 *   [15,14,12,16]
 * ], 
 * 
 * rotate the input matrix in-place such that it becomes:
 * [
 *   [15,13, 2, 5],
 *   [14, 3, 4, 1],
 *   [12, 6, 8, 9],
 *   [16, 7,10,11]
 * ]
 */

public class Solution {
    public void rotate(int[][] matrix) {
        if (matrix == null) {
            throw new NullPointerException();
        }

        // flip / diagonal
        for (int i = 0; i < matrix.length - 1; ++i) {
            for (int j = 0; j < matrix.length - 1 - i; ++j) {
                swap(matrix, i, j, matrix.length - 1 - j, matrix.length - 1 - i);
            }
        }

        // flip - horizontal
        for (int i = 0; i < matrix.length / 2; ++i) {
            for (int j = 0; j < matrix.length; ++j) {
                swap(matrix, i, j, matrix.length - 1 - i, j);
            }
        }
    }

    private void swap(int[][] matrix, int i1, int j1, int i2, int j2) {
        int swap = matrix[i1][j1];
        matrix[i1][j1] = matrix[i2][j2];
        matrix[i2][j2] = swap;
    }
}