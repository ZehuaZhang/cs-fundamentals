/*
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.



Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2


Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/

function subarraySum(nums: number[], target: number): number {
  let result = 0;
  let sum = 0;
  const sumCountMap = new Map<number, number>([[0, 1]]);
  for (const num of nums) {
    sum += num;
    result += sumCountMap.get(sum - target) || 0;
    sumCountMap.set(sum, (sumCountMap.get(sum) || 0) + 1);
  }
  return result;
}
