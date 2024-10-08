/**
 * Find Minimum in Rotated Sorted Array
 * 
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * 
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * Find the minimum element.
 * 
 * You may assume no duplicate exists in the array.
 */

public class Solution {
    public int findMin(int[] nums) {
        int left = 0, right = nums.length - 1;

        while (left < right && nums[left] >= nums[right]) {
            int middle = left + (right - left) / 2;
            if (nums[middle] < nums[left]) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }

        return nums[left];
    }
}