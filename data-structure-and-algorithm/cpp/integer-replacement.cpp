// 397. Integer Replacement
// Difficulty: Easy

// Given a positive integer n and you can do operations as follow:

// If n is even, replace n with n/2.
// If n is odd, you can replace n with either n + 1 or n - 1.
// What is the minimum number of replacements needed for n to become 1?

// Example 1:

// Input:
// 8

// Output:
// 3

// Explanation:
// 8 -> 4 -> 2 -> 1
// Example 2:

// Input:
// 7

// Output:
// 4

// Explanation:
// 7 -> 8 -> 4 -> 2 -> 1
// or
// 7 -> 6 -> 3 -> 2 -> 1

// Time:  O(logn)
// Space: O(1)

// Iterative solution.
class Solution {
public:
  int integerReplacement(int n) {
    int res = 0;
    while (n > 3) {  
      if (!(n & 1)) {
        n >>= 1;  
      } else if (n & 2) {
        ++n;  
      } else {
        --n;  
      }
      ++res;  
    }  
    return res + n - 1;  
  }
};