// 335. Self Crossing
// Difficulty: Hard

// You are given an array x of n positive numbers. 
// You start at point (0,0) and moves x[0] metres to the north,then x[1] metres to the west, x[2] metres to the south, 
// x[3] metres to the east and so on. In other words, after each move your direction changes counter-clockwise.

// Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.

// Example 1:
// Given x = [2, 1, 1, 2],
// ┌───┐
// │   │
// └───┼──>
//     │

// Return true (self crossing)
// Example 2:
// Given x = [1, 2, 3, 4],
// ┌──────┐
// │      │
// │
// │
// └────────────>

// Return false (not self crossing)
// Example 3:
// Given x = [1, 1, 1, 1],
// ┌───┐
// │   │
// └───┼>

// Return true (self crossing)

// Time:  O(n)
// Space: O(1)

class Solution {
public:
  bool isSelfCrossing(vector<int>& x) {
    if (x.size() >= 5 && x[3] == x[1] && x[4] + x[0] >= x[2]) {
      // overlap in a loop:
      //     2
      // 3 ┌────┐
      //   └─══>┘1
      //   4  0
      return true;
    }

    for (int i = 3; i < x.size(); ++i) {
      if (x[i] >= x[i - 2] && x[i - 3] >= x[i - 1]) {
        // intersection case 1:
        //    i-2
        // i-1┌─┐
        //    └─┼─>i
        //     i-3
        return true;
      } else if (i >= 5 && 
        x[i - 4] <= x[i - 2] && x[i] + x[i - 4] >= x[i - 2] &&
        x[i - 1] <= x[i - 3] && x[i - 1] + x[i - 5] >= x[i - 3]) {
        // intersection case 2:
        //    i-4
        //    ┌──┐ 
        //    │i<┼─┐
        // i-3│ i-5│i-1
        //    └────┘
        //      i-2
        return true;
      }
    }
    return false;
  }
};
