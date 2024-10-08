// 452. Minimum Number of Arrows to Burst Balloons
// Difficulty: Medium

// There are a number of spherical balloons spread in two-dimensional space.
// For each balloon, provided input is the start and end coordinates of the horizontal diameter.
// Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice.
// Start is always smaller than end. There will be at most 104 balloons.

// An arrow can be shot up exactly vertically from different points along the x-axis.
// A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend.
// There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely.
// The problem is to find the minimum number of arrows that must be shot to burst all balloons.

// Example:

// Input:
// [[10,16], [2,8], [1,6], [7,12]]

// Output:
// 2

// Explanation:
// One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6])
// and another arrow at x = 11 (bursting the other two balloons).

// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
  int findMinArrowShots(vector<pair<int, int>>& points) {
    sort(points.begin(), points.end());

    int result = 0;
    for (int i = 0; i < points.size();) {
      int j = i + 1;
      int right = points[i].second;
      while (j < points.size() && points[j].first <= right) {
        right = min(right, points[j].second);
        ++j;
      }
      ++result;
      i = j;
    }
    return result;
  }
};