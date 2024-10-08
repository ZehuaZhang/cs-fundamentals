// 233. Number of Digit One
// Difficulty: Hard

// Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

// For example:
// Given n = 13,
// Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

// Hint:
// Beware of overflow.

// Time:  O(logn) = O(1)
// Space: O(1)

class Solution {
public:
  int countDigitOne(int n) {
    int res = 0;
    for (long k = 1; k <= n; k *= 10) {
      long r = n / k, m = n % k;
      res += (r + 8) / 10 * k + (r % 10 == 1 ? m + 1 : 0);
    }
    return res;
  }
};
