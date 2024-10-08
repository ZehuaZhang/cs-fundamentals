/*
325. Maximum Size Subarray Sum Equals k

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
  const n = nums.length;
  let rslt = 0;
  const map = new Map<number, number>();
  for (let i = 0, sum = 0; i < n; ++i) {
    sum += nums[i];
    if (sum === target) {
      rslt = i + 1;
    } else if (map.has(sum - target)) {
      rslt = Math.max(rslt, i - map.get(sum - target));
    }
    if (!map.has(sum)) {
      map.set(sum, i);
    }
  }

  return rslt;
}
