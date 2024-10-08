// 11. Container With Most Water
// Difficulty: Medium

// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
// n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
// Find two lines, which together with x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container.

// Time : O(n)
// Space: O(1)

class Solution {
public:
  int maxArea(vector<int>& height) {
    int ans = 0;
    for (int left = 0, right = height.size() - 1; left < right;) {
      ans = max(ans, min(height[left], height[right]) * (right - left));
      if (height[left] <= height[right]) {
        left++;
      } else {
        right--;
      }
    }
    return ans;
  }
};
