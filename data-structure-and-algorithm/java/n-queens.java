/**
 * N-Queens
 * 
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 * 
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 * 
 * [
 *  [".Q..",  // Solution 1
 *   "...Q",
 *   "Q...",
 *   "..Q."],
 * 
 *  ["..Q.",  // Solution 2
 *   "Q...",
 *   "...Q",
 *   ".Q.."]
 * ]
 */

import java.util.Arrays;
import java.lang.*;

public class Solution {
	public List<List<String>> solveNQueens(int n) {
		List<List<String>> result = new List<list<String>>();
		int[] columnPositionInRow = new int[n];
		Arrays.fill(columnPositionInRow, -1);
		solveNQueensHelper(row, n, columnPositionInRow, result);
		return result;
	}

	private solveNQueensHelper(int row, int n, int[] columnPositionInRow, List<List<String>> result) {
		if (row == n) {
			List<String> entryOfResult = new List<String>();
			for (int i = 0; i < n; ++i) {
				char[] string = new char[n];
				Arrays.fill(string, '.');
				StringBuilder stringBuilder = new StringBuilder(string);
				stringBuilder.setCharAt(columnPositionInRow[i], 'Q');

				entryOfResult.add(stringBuilder.toString());
			}
			result.add(entryOfResult);
		} else {
			for (int col = 0; col < n; ++col) {
				if (isValid(columnPositionInRow, row, col)) {
					columnPositionInRow[row] = col;
					solveNQueensHelper(row + 1, n, columnPositionInRow, result);
					columnPositionInRow[row] = -1;
				}
			}
		}
	}

	private bool isValid(int[] columnPositionInRow, int row, int col) {
		for (int i = 0; i < columnPositionInRow.length; ++i) {
			if (columnPositionInRow[i] != -1) {
				if (columnPositionInRow[i] == col || Math.abs(row - i) == Math.abs(col - columnPositionInRow[i])) {
					return false;
				}
			}
		}
		return true;
	}
}
