// 400. Nth Digit
// Difficulty: Easy

// Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

// Note:
// n is positive and will fit within the range of a 32-bit signed integer (n < 231).

// Example 1:

// Input:
// 3

// Output:
// 3
// Example 2:

// Input:
// 11

// Output:
// 0

// Explanation:
// The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.

// Time:  O(logn)
// Space: O(1)

class Solution {
public:
  int findNthDigit(int n) {
    int len = 1;
    while (n > len * 9 * pow(10, len - 1)) {
      n -= len * 9 * pow(10, len - 1);
      ++len;
    }
    const int num = pow(10, len - 1) + (n - 1) / len;

    int nth = num / pow(10, (len - 1) - (n - 1) % len);
    return nth % 10;
  }
};