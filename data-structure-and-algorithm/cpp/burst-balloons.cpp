// 312. Burst Balloons
// Difficulty: Hard

// Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. 
// You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. 
// Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

// Find the maximum coins you can collect by bursting the balloons wisely.

// Note: 
// (1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
// (2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

// Example:
// Given [3, 1, 5, 8]

// Return 167

//     nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//    coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

// Time:  O(n^3)
// Space: O(n^2)

class Solution {
public:
  int maxCoins(vector<int>& nums) {
    nums.emplace(nums.begin(), 1);
    nums.emplace_back(1);
    
    vector<vector<int>> maxCoins(nums.size(), vector<int>(nums.size()));
    for (int len = 2; len < nums.size(); ++len) {
      for (int left = 0; left + len < nums.size(); ++left) {
        for (int i = left + 1, right = left + len; i < right; ++i) {  // left, i, right
          maxCoins[left][right] = max(maxCoins[left][right], nums[left] * nums[i] * nums[right] + maxCoins[left][i] + maxCoins[i][right]);
        }
      }
    }
    return maxCoins[0][nums.size() - 1];
  }
};
