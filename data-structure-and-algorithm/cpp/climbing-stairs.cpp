// 70. Climbing Stairs
// Difficulty: Easy

// You are climbing a stair case. It takes n steps to reach to the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Time : O(n)
// Space: O(1)

class Solution {
public:
  int climbStairs(int n) {
    int curr = 1, prev = 0, int prevPrev = 0;
    for (int i = 1; i <= n; ++i) {
      prevPrev = prev;
      prev = curr;
      curr = prevPrev + prev;
    }
    return curr;
  }
};