/*
Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Example 2:

Input: n = 1, k = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20
1 <= k <= n
*/

function combine(n, k) {
    const result = [];
    dfs(n, k, 1, [], result);
    return result;
};

function dfs(n, k, left, curr, result) {
    if (curr.length === k) {
        result.push([...curr]);
        return;
    }
    for (let i = left; i <= n; ++i) {
        curr.push(i);
        dfs(n, k, i + 1, curr, result);
        curr.pop();
    }
}