/*
51. N-Queens

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9
*/

function solveNQueens(n: number): string[][] {
  const cols = Array(n).fill(false);
  const diag1 = Array(2 * n - 1);
  const diag2 = Array(2 * n - 1);

  const path: number[] = [];
  const rslt: string[][] = [];

  dfs();

  return rslt;

  function dfs() {
    const row = path.length;
    if (row === n) {
      return rslt.push(
        path.map((r) => {
          const a = [...".".repeat(n)];
          a[r] = "Q";
          return a.join("");
        })
      );
    }

    for (let i = 0; i < n; ++i) {
      if (!cols[i] && !diag1[i + row] && !diag2[i - row + n - 1]) {
        cols[i] = diag1[i + row] = diag2[i - row + n - 1] = true;
        path.push(i);
        dfs();
        path.pop();
        cols[i] = diag1[i + row] = diag2[i - row + n - 1] = false;
      }
    }
  }
}
