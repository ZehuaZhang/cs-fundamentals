/**
 * House Robber II
 * 
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle.
 * That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 * 
 * Example 1:
 * 
 * Input: [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
 *              because they are adjacent houses.
 * Example 2:
 * 
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 *              Total amount you can rob = 1 + 3 = 4.
 */

public class Solution {
    public int rob(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }

        return Math.max(robHelper(nums, 0, nums.length - 2), robHelper(nums, 1, nums.length - 1));
    }

    private int robHelper(int[] nums, int start, int end) {
        int curr = nums[start], prev = 0, prevPrev = 0;
        for (int i = start + 1; i <= end; ++i) {
            prevPrev = prev;
            prev = currr;
            curr = Math.max(nums[i] + prevPrev, prev);
        }

        return curr;
    }
}
