/*
220. Contains Duplicate III

You are given an integer array nums and two integers indexDiff and valueDiff.

Find a pair of indices (i, j) such that:

i != j,
abs(i - j) <= indexDiff.
abs(nums[i] - nums[j]) <= valueDiff, and
Return true if such pair exists or false otherwise.

 

Example 1:

Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
Output: true
Explanation: We can choose (i, j) = (0, 3).
We satisfy the three conditions:
i != j --> 0 != 3
abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0
Example 2:

Input: nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
Output: false
Explanation: After trying all the possible pairs (i, j), we cannot satisfy the three conditions, so we return false.
 

Constraints:

2 <= nums.length <= 105
-109 <= nums[i] <= 109
1 <= indexDiff <= nums.length
0 <= valueDiff <= 109
*/

function containsNearbyAlmostDuplicate(
  nums: number[],
  indexDiff: number,
  valueDiff: number
): boolean {
  if (valueDiff < 0) {
    return false;
  }
  const m = new Map<number, number>();
  const w = valueDiff + 1;
  for (let i = 0; i < nums.length; ++i) {
    const id = getId(nums[i]);
    if (
      m.has(id) ||
      (m.has(id - 1) && Math.abs(nums[i] - m.get(id - 1)) < w) ||
      (m.has(id + 1) && Math.abs(nums[i] - m.get(id + 1)) < w)
    ) {
      return true;
    }
    m.set(id, nums[i]);
    if (i >= indexDiff) {
      m.delete(getId(nums[i - indexDiff]));
    }
  }
  return false;

  function getId(n: number) {
    return n < 0 ? Math.trunc((n + 1) / w) - 1 : Math.trunc(n / w);
  }
}
