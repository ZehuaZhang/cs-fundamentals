// 374. Guess Number Higher or Lower
// Difficulty: Easy

// We are playing the Guess Game. The game is as follows:

// I pick a number from 1 to n. You have to guess which number I picked.

// Every time you guess wrong, Ill tell you whether the number is higher or lower.

// You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

// -1 : My number is lower
//  1 : My number is higher
//  0 : Congrats! You got it!
// Example:
// n = 10, I pick 6.

// Return 6.

// Time:  O(logn)
// Space: O(1)

#import <Foundation/Foundation.h>

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

int guessNumber(int n) {
  int left = 1, right = n;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (guess(mid) <= 0) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return left;
}