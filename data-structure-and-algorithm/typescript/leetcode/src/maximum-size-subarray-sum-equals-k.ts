/*
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:

Input: nums = [1, -1, 5, -2, 3], k = 3
Output: 4
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
Example 2:

Input: nums = [-2, -1, 2, 1], k = 1
Output: 2
Explanation: The subarray [-1, 2] sums to 1 and is the longest.
Follow Up:
Can you do it in O(n) time?
*/

function maxSubArrayLen(nums: number[], target: number): number {
  let sum = 0;
  let result = 0;
  const sumIndexMap = new Map<number, number>();
  for (let i = 0; i < nums.length; ++i) {
    sum += nums[i];
    if (sum === target) {
      result = i + 1;
    } else if (sumIndexMap.has(sum - target)) {
      result = Math.max(result, i - sumIndexMap.get(sum - target)!);
    }
    if (!sumIndexMap.has(sum)) {
      sumIndexMap.set(sum, i);
    }
  }
  return result;
}
