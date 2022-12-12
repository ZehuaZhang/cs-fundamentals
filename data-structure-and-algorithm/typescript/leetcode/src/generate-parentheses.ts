/*
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

function generateParenthesis(count: number): string[] {
  if (count === 0) {
    return [''];
  }
  if (count === 1) {
    return ['()'];
  }
  const result: string[] = [];
  for (let i = 0; i < count; ++i) {
    for (const inner of generateParenthesis(i)) {
      for (const outer of generateParenthesis(count - 1 - i)) {
        result.push(`(${inner})${outer}`);
      }
    }
  }
  return result;
}
