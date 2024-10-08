// 219. Contains Duplicate II
// Difficulty: Easy

// Given an array of integers and an integer k,
// find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] 
// and the difference between i and j is at most k

// Time:  O(n)
// Space: O(n)

class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> index;
    for (int i = 0; i < nums.size(); ++i) {
      if (index.count(nums[i])) {
        if (i - index[nums[i]] <= k) {
          return true;
        }
      }
      index[nums[i]] = i;
    }
    return false;
  }
};
