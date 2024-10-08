/*
22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

function generateParenthesis(n: number): string[] {
  if (n === 0) {
    return [""];
  }

  if (n === 1) {
    return ["()"];
  }

  const rslt: string[] = [];

  for (let i = 0; i < n; ++i) {
    for (const a of generateParenthesis(i)) {
      for (const b of generateParenthesis(n - i - 1)) {
        rslt.push(`(${a})${b}`);
      }
    }
  }

  return rslt;
}
