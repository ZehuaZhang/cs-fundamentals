/**
 * Majority Element
 * 
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always exist in the array.
 * 
 * Example 1:
 * 
 * Input: [3,2,3]
 * Output: 3
 * Example 2:
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 */

public class Solution {
    public int majorityElement(int[] nums) {
        if (nums == null) {
            throw new NullPointerException();
        }

        if (nums.length == 0) {
            throw new IllegalArgumentException();
        }

        int count = 0;
        int result = 0;
        for (int num : nums) {
            if (count == 0) {
                result = num;
                ++count;
            } else if (result == num) {
                ++count;
            } else {
                --count;
            }
        }
    }
}
