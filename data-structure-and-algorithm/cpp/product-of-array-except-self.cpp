// 238. Product of Array Except Self
// Difficulty: Medium

// Given an array of n integers where n > 1, nums, return an array output 
// such that output[i] is equal to the product of all the elements of nums except nums[i].

// Solve it without division and in O(n).

// For example, given [1,2,3,4], return [24,12,8,6].

// Follow up:
// Could you solve it with constant space complexity? 
// (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

// Time:  O(n)
// Space: O(1)

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    if (nums.empty()) {
      return vector<int>();
    }

    vector<int> leftProduct(nums.size());

    leftProduct[0] = 1;
    for (int i = 1; i < nums.size(); ++i) {
      leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
    }

    int rightProduct = 1;
    for (int i = nums.size() - 2; i >= 0; --i) {
      rightProduct *= nums[i + 1];
      leftProduct[i] *= rightProduct;
    }
    return leftProduct;
  }
};
