/*
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b


Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]


Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104
*/

function findClosestElements(
  numList: number[],
  k: number,
  target: number
): number[] {
  let left = 0;
  let right = numList.length - k;
  while (left < right) {
    const mid = (left + right) >> 1;
    if (target - numList[mid] > numList[mid + k] - target) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return numList.slice(left, left + k);
}
