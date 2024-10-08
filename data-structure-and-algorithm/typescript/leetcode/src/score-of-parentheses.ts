/*
Given a balanced parentheses string s, compute the score of the string based on the following rule:

() has score 1
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.


Example 1:

Input: s = "()"
Output: 1
Example 2:

Input: s = "(())"
Output: 2
Example 3:

Input: s = "()()"
Output: 2
Example 4:

Input: s = "(()(()))"
Output: 6


Note:

s is a balanced parentheses string, containing only ( and ).
2 <= s.length <= 50
*/

function scoreOfParentheses(input: string): number {
  let result = 0;
  let count = 0;
  for (let i = 0; i < input.length; ++i) {
    if (input[i] === '(') {
      ++count;
    } else {
      --count;
    }
    if (input[i] === ')' && input[i - 1] === '(') {
      result += Math.pow(2, count);
    }
  }
  return result;
}
