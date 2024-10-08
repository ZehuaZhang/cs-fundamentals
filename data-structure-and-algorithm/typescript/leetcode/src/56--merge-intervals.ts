/*
56. Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/

function merge(intervals: number[][]): number[][] {
  const n = intervals.length;

  intervals.sort(([s1, e1], [s2, e2]) => {
    if (s1 === s2) {
      return e1 - e2;
    }
    return s1 - s2;
  });

  const rslt: number[][] = n ? [intervals[0]] : [];
  for (let i = 1; i < n; ++i) {
    const [s1, e1] = rslt[rslt.length - 1];
    const [s2, e2] = intervals[i];

    if (e1 < s2) {
      rslt.push(intervals[i]);
    } else {
      rslt[rslt.length - 1][1] = Math.max(e1, e2);
    }
  }

  return rslt;
}
