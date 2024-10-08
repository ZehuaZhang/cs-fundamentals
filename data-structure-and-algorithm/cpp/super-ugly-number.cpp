// 313. Super Ugly Number
// Difficulty: Medium

// Write a program to find the nth super ugly number.

// Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. 
// For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers 
// given primes = [2, 7, 13, 19] of size 4.

// Note:
// (1) 1 is a super ugly number for any given primes.
// (2) The given numbers in primes are in ascending order.
// (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.

// Time:  O(n * k)
// Space: O(n + k)
// DP solution. (596ms)
class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> uglies(n), factors(primes), idx(primes.size());
    uglies[0] = 1;
    for (int i = 1; i < n; ++i) {
      k = distance(factors.begin(), min_element(factors.begin(), factors.end()));
      uglies[i] = factors[k];
      factors[k] = primes[k] * uglies[++idx[k]];
    }
    return uglies[n - 1]; 
  }
};