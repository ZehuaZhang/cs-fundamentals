/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, assume that your function returns 231 − 1 when the division result overflows.



Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.
Example 3:

Input: dividend = 0, divisor = 1
Output: 0
Example 4:

Input: dividend = 1, divisor = 1
Output: 1


Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0
*/

// O(logN^2)
function divide(dividend: number, divisor: number): number {
  const max = Math.pow(2, 31) - 1;
  const min = -1 * Math.pow(2, 31);

  if (dividend === min && divisor === -1) {
    return max;
  }

  let result = 0;
  for (let a = Math.abs(dividend), b = Math.abs(divisor); a >= b; ) {
    let c = b;
    for (let i = 0; a >= c && c > 0; ++i, c <<= 1) {
      a -= c;
      result += 1 << i;
    }
  }

  return dividend > 0 === divisor > 0 ? result : -result;
}
