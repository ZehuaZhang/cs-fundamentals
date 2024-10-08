/*
421. Maximum XOR of Two Numbers in an Array
Difficulty: Medium

Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 2^31.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.

Time:  O(n)
Space: O(n)
*/

function findMaximumXOR(nums: number[]): number {
  let result = 0;

  for (let i = 31; i >= 0; --i) {
    result <<= 1;
    const prefixSet = new Set<number>();
    for (const num of nums) {
      prefixSet.add(num >> i);
    }
    for (const prefix of prefixSet) {
      if (prefixSet.has((result | 1) ^ prefix)) {
        ++result;
        break;
      }
    }
  }
  return result;
}
