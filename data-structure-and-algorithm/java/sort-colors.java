/**
 * Sort Colors
 * 
 * Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 * 
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 * 
 * click to show follow up.
 * 
 * Follow up:
 * A rather straight forward solution is a two-pass algorithm using counting sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
 * 
 * Could you come up with an one-pass algorithm using only constant space?
 */

public class Solution {
    public void sortColors(int[] nums) {
        if (nums == null) {
            throw new NullPointerException();
        }

        int red = 0, blue = nums.length - 1;
        for (int i = 0; i < nums.length; ++i) {
            if (A[i] == 0) {
                swap(nums, i, red++);
            } else if (A[i] == 2) {
                swap(nums, i--, blue--);
            }
        }
    }
    
    private void swap(int[] nums, int i, int j) {
        nums[i] = nums[i] ^ nums[j];
        nums[j] = nums[i] ^ nums[j];
        nums[i] = nums[i] ^ nums[j];
    }
}
