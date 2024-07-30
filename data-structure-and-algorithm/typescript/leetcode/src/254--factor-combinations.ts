/*
254. Factor Combinations

Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.

Write a function that takes an integer  n  and return all possible combinations of its factors.

Note:

You may assume that  n  is always positive.
Factors should be greater than 1 and less than  n.
Example 1:

Input: 1
Output: []

Example 2:

Input: 37
Output:[]

Example 3:

Input: 12
Output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]

Example 4:

Input: 32
Output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
*/

function getFactors(num: number): number[][] {
  const path: number[] = [];
  const rslt: number[][] = [];

  dfs(2, num);

  return rslt;

  function dfs(i0: number, tgt: number) {
    if (tgt === 1 && path.length > 1) {
      return rslt.push([...path]);
    }

    for (let i = i0; i < tgt; ++i) {
      if (tgt % i === 0) {
        path.push(i);
        dfs(i, tgt / i);
        path.pop();
      }
    }
  }
}
