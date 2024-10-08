// 167. Two Sum II - Input array is sorted
// Difficulty : Medium

// Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
// Please note that your returned answers (both index1 and index2) are not zero-based.
// You may assume that each input would have exactly one solution.
// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2

// Time:  O(n)
// Space: O(1)

#import <Foundation/Foundation.h>

NSArray* twoSumII(NSArray* nums,  NSInteger target) {
  NSInteger left = 0;
  NSInteger right = nums.count - 1;
  while ( left <= right ) {
    NSInteger sum = [nums[left] integerValue] + [nums[right] integerValue];
    
    if (sum > target) {
      right--;
    } else if (sum < target) {
      left++;
    } else {
      return @[@(left + 1),@(right + 1)];
    }
  };
  return nil;
}