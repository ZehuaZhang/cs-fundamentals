// 120. Triangle
// Difficulty: Medium

// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

// For example, given the following triangle
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

// Note:
// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

// Time Complexity: O(n^2)
// Space Complexity: O(n)

#import <Foundation/Foundation.h>

NSInteger minimumTotal(NSMutableArray* triangle) {
  for (NSInteger i = [triangle count] - 2; i >= 0; --i) {
    for (NSInteger j = 0; j <= i; ++j) {
      triangle[i][j] = @([triangle[i][j] integerValue] + MIN([triangle[i + 1][j] integerValue], [triangle[i + 1][j + 1] integerValue]));
    }
  }
  return [triangle[0][0] integerValue];
}
