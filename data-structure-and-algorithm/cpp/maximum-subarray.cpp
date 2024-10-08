// 53. Maximum Subarray
// Difficulty: Medium

// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

// For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
// the contiguous subarray [4,-1,2,1] has the largest sum = 6.

// More practice:
// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

// Time:  O(n)
// Space: O(n)

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int curSum = 0;
    int maxSum = INT_MIN;
    for (auto num : nums) {
      curSum = max(curSum + num, num);
      maxSum = max(maxSum, curSum);
    }
    return maxSum;
  }
};