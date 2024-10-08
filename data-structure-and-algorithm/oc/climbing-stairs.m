// 70. Climbing Stairs
// Difficulty: Easy

// You are climbing a stair case. It takes n steps to reach to the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Time : O(n)
// Space: O(1)

#import <Foundation/Foundation.h>

int climbStairs(int n) {
  int prev = 0, curr = 1;
  for (int i = 1; i <= n; ++i) {
    int nextPrev = curr;
    curr += prev;
    prev = nextPrev;
  }
  return curr;
}
