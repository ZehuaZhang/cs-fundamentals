// 62. Unique Paths
// Difficulty: Medium

// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time.
// The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// Note: m and n will be at most 100.

// Time Complexity: O(mn)
// Space Complexity: O(n)

class Solution2 {
public:
  int uniquePaths(int m, int n) {
    vector<int> f(n, 1);
    for(int i = 1; i < m; ++i) {
      for(int j = 1; j < n; ++j) {
        f[j] += f[j - 1];
      }
    }
    return f[n - 1];
  }
};