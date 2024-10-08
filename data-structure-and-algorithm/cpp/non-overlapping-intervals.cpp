// 435. Non-overlapping Intervals
// Difficulty: Medium

// Given a collection of intervals,
// find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

// Note:
// You may assume the interval's end point is always bigger than its start point.
// Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
// Example 1:
// Input: [ [1,2], [2,3], [3,4], [1,3] ]

// Output: 1

// Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
// Example 2:
// Input: [ [1,2], [1,2], [1,2] ]

// Output: 2

// Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
// Example 3:
// Input: [ [1,2], [2,3] ]

// Output: 0

// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
  int eraseOverlapIntervals(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) { return a.start < b.start; });

    int result = 0, prev = 0;
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i].start < intervals[prev].end) {
        if (intervals[i].end < intervals[prev].end) {
          prev = i;
        }
        ++result;
      } else {
        prev = i;
      }
    }
    return result;
  }
};