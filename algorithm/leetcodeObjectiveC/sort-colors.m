// 75. Sort Colors
// Difficulty: Medium

// Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent,
// with the colors in the order red, white and blue.

// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

// Note:
// You are not suppose to use the library sort function for this problem.

// Follow up:
// A rather straight forward solution is a two-pass algorithm using counting sort.
// First, iterate the array counting number of 0, 1, and 2, then overwrite array with total number of 0
// , then 1 and followed by 2.

// Could you come up with an one-pass algorithm using only constant space?

// Time:  O(n)
// Space: O(1)

// Tri-Partition solution.

#import <Foundation/Foundation.h>

void sortColors(NSMutableArray** nums) {
  const int target = 1;
  for (NSInteger red = 0, white = 0, blue = [*nums count] - 1; white <= blue;) {
    if ([(*nums)[white] intValue] < target) {
      [*nums exchangeObjectAtIndex:red++ withObjectAtIndex:white++];
    } else if ([(*nums)[white] intValue]> target) {
      [*nums exchangeObjectAtIndex:white withObjectAtIndex:blue--];
    } else {
      ++white;
    }
  }
}