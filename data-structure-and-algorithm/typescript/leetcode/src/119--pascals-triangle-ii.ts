/*
119. Pascal's Triangle II

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]
 

Constraints:

0 <= rowIndex <= 33
 

Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?
*/

function getRow(rowIndex: number): number[] {
  let prev: number[] = [];
  let rslt: number[] = [];
  for (let i = 0; i <= rowIndex; ++i) {
    rslt = Array(i + 1).fill(1);

    for (let j = 1; j < i; ++j) {
      rslt[j] = prev[j] + prev[j - 1];
    }

    prev = rslt;
  }

  return rslt;
}
