// 50. Pow(x, n)
// Difficulty: Medium

// Implement pow(x, n).

// Time:  O(logn) = O(1)
// Space: O(logn)

#import <Foundation/Foundation.h>

double power(double x, int n) {
  if (n == 0) {
    return 1;
  }
  double half = power(x, n / 2);
  if (n % 2 == 0) {
    return half * half;
  }
  return x * half * half;
}

double myPow(double x, int n) {
  if (n < 0) {
    return 1.0 / power(x, -n);
  }
  return power(x, n);
}

