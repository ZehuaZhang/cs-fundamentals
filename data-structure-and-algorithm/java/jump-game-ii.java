/**
 * Jump Game II
 * 
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * For example:
 * Given array A = [2,3,1,1,4]
 * 
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 */

public class Solution {
    public int jump(int[] nums) {
        int result = 0;
        int maxDistanceForPrevJump = 0, maxDistanceForCurrJump = 0;
        for (int i = 0; i < nums.length - 1; ++i) {
            maxDistanceForCurrJump = Math.max(maxDistanceForCurrJump, i + nums[i]);
            if (i == maxDistanceForPrevJump) {
                maxDistanceForPrevJump = maxDistanceForCurrJump;
                ++result;
                if (maxDistanceForCurrJump >= nums.length - 1) {
                    break;
                }
            }
        }
        return result;
    }
}
