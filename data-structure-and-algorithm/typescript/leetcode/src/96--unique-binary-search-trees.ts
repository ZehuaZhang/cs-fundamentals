/*
96. Unique Binary Search Trees

Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

Example 1:


Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 19
*/

function numTrees(n: number): number {
  const memo = Array(n + 1).fill(0);
  return dfs(n);

  function dfs(cnt: number) {
    if (cnt <= 1) {
      return 1;
    }
    if (memo[cnt]) {
      return memo[cnt];
    }
    for (let i = 1; i <= cnt; ++i) {
      memo[cnt] += dfs(i - 1) * dfs(cnt - i);
    }
    return memo[cnt];
  }
}
