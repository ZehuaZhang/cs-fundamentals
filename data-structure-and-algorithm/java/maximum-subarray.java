/**
 * Maximum Subarray
 * 
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 * 
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 * 
 * click to show more practice.
 * 
 * More practice:
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */

public class Solution {
    public int maxSubArray(int[] nums) {
        int result = Integer.MIN_VALUE, currSumMax = 0;
        for (int num : nums) {
            currSumMax = Math.max(currSumMax, currSumMax + num);
            result = Math.max(result, currSumMax);
        }
        return result;
    }
}
