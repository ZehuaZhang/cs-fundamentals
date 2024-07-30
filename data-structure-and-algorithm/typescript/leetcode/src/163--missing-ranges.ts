/*
163. Missing Ranges

Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

Example:

Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]
*/

function findMissingRanges(
  nums: number[],
  lower: number,
  upper: number
): string[] {
  const n = nums.length;
  const rslt: string[] = [];
  let prev = lower - 1;
  for (let i = 0; i <= n; ++i) {
    const curr = i === n ? upper + 1 : nums[i];
    if (curr - prev >= 2) {
      const [l, r] = [prev + 1, curr - 1];
      rslt.push(l === r ? String(l) : [l, r].join("->"));
    }
    prev = curr;
  }

  return rslt;
}
