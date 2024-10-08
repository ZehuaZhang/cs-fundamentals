// 254. Factor Combinations
// Difficulty : Medium

// Numbers can be regarded as product of its factors. For example,

// 8 = 2 x 2 x 2;
//   = 2 x 4.
// Write a function that takes an integer n and return all possible combinations of its factors.

// Note: 
// Each combination factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], not [6, 2].
// You may assume that n is always positive.
// Factors should be greater than 1 and less than n.


// Examples: 
// input: 1
// output: 

// []
// input: 37
// output: 

// []
// input: 12
// output:

// [
//   [2, 6],
//   [2, 2, 3],
//   [3, 4]
// ]
// input: 32
// output:

// [
//   [2, 16],
//   [2, 2, 8],
//   [2, 2, 2, 4],
//   [2, 2, 2, 2, 2],
//   [2, 4, 4],
//   [4, 8]
// ]

// Time:  O(nlogn) = logn * n^(1/2) * n^(1/4) * ... * 1
// Space: O(logn)

// DFS solution.
class Solution {
public:
  vector<vector<int>> getFactors(int n) {
    vector<vector<int>> res;
    vector<int> path;
    helper(n, 2, path, res);
    return res;
  }

private:
  void helper(int n, int start, vector<int>& path, vector<vector<int>>& res) {
    if (n == 1 || path.size() > 1) {
      res.push_back(path);
    } else {
      for (int i = start; i <= n; ++i) {
        if (n % i == 0) {
          path.push_back(i);
          helper(n / i, i, path, res);
          path.pop_back();
        }
      }
    }
  }
};