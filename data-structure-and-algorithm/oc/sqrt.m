// 69. Sqrt(x)
// Difficulty: Medium

// Implement int sqrt(int x).

// Compute and return the square root of x.

// Time : O(n)
// Space: O(1)

#import <Foundation/Foundation.h>

int mySqrt(int x) {
  int left = 1;
  int right = x;
  int prevMid = 0;
  
  while (left <= right) {
    int mid = left + (right - left) / 2;
    
    if (x / mid > mid) {
      left = mid + 1;
      prevMid = mid;
    } else if (x / mid < mid) {
      right = mid - 1;
    } else {
      return mid;
    }
  }
  
  return prevMid;
}
