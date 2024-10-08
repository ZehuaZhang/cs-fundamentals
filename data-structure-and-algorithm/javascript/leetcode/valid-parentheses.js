/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

/**
 * @param { string } s
 * @return { boolean }
 */
var isValid = function(s) {
    const left = "([{";
    const map = new Map([
        [')', '('],
        ['}', '{'],
        [']', '[']
    ])
    const stack = []
    for (const c of s) {
        if (left.includes(c)) {
            stack.push(c)
        } else if (map.get(c) !== stack[stack.length - 1]) {
            return false;
        } else {
            stack.pop();
        }
    }
        
    return stack.length === 0
};