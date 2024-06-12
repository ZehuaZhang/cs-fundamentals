/*
9. Palindrome Number

Given an integer x, return true if x is a 
palindrome
, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:

-231 <= x <= 231 - 1
 

Follow up: Could you solve it without converting the integer to a string?
*/

function isPalindrome(x: number): boolean {
  if (Math.sign(x) < 0) {
    return false;
  }
  const max = Math.pow(2, 31) - 1;
  let reversed = 0;
  for (let num = x; num; num = Math.trunc(num / 10)) {
    if (
      reversed > Math.trunc(max / 10) ||
      (reversed === Math.trunc(max / 10) && num % 10 > max % 10)
    ) {
      return false;
    }
    reversed = reversed * 10 + (num % 10);
  }
  return reversed === x;
}
