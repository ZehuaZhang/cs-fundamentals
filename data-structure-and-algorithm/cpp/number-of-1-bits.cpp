// 191. Number of 1 Bits
// Difficulty: Easy

// Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

// For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

// Time:  O(logn) = O(32)
// Space: O(1)

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    for (; n; n &= n - 1) {
      ++count;
    }
    return count;
  }
};
