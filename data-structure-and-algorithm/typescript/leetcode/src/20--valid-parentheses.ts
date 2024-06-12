/*
20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

function isValid(s: string): boolean {
  const lefts = '({[';
  const map = {
    ')': '(',
    '}': '{',
    ']': '[',
  };
  const stk: string[] = [];
  for (const c of s) {
    if (lefts.includes(c)) {
      stk.push(c);
    } else if (map[c] !== stk[stk.length - 1]) {
      return false;
    } else {
      stk.pop();
    }
  }

  return stk.length === 0;
}
