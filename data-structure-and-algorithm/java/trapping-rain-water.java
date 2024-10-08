/**
 * Trapping Rain Water
 * 
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
 */

public class Solution {
    public int trap(int[] height) {
        int level = 0, result = 0;
        for (int left = 0, right = height.length - 1; left < right;) {
            int lowerHeight = height[height[left] < height[right] ? left++ : right--];
            level = Math.max(level, lower);
            result += level - lower;
        }
        return result;
    }
}
