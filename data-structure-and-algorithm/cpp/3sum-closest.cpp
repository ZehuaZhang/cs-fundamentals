// 16. 3Sum Closest
// Difficulty: Medium

// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
// Return the sum of the three integers. You may assume that each input would have exactly one solution.

// For example, given array S = {-1 2 1 -4}, and target = 1.

// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
  int threeSumClosest(vector<int> nums, int target) {
    int ans = INT_MAX;
    int minDiff = INT_MAX;
    
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < nums.size() - 2; ++i) {
      for (int left = i + 1, right = nums.size() - 1; left < right;) {
        const auto sum = nums[i] + nums[left] + nums[right];
        if (sum > target) {
          --right;
        } else if (sum < target) {
          ++left;
        } else {
          return target;
        }
        
        if (abs(sum - target) < minDiff) {
          minDiff = abs(sum - target);
          ans = sum;
        }
      }
    }
    return ans;
  }
};