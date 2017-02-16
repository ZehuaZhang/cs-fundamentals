// 322. Coin Change
// Difficulty: Medium

// You are given coins of different denominations and a total amount of money amount.
// Write a function to compute the fewest number of coins that you need to make up that amount.
// If that amount of money cannot be made up by any combination of the coins, return -1.

// Example 1:
// coins = [1, 2, 5], amount = 11
// return 3 (11 = 5 + 5 + 1)

// Example 2:
// coins = [2], amount = 3
// return -1.

// Note:
// You may assume that you have an infinite number of each kind of coin.

// Time:  O(n * k), n is the number of coins, k is the amount of money
// Space: O(k)

#import <Foundation/Foundation.h>

// DP solution

int coinChange(NSArray* coins, int amount) {
  int amounts[amount + 1];
  amounts[0] = 0;
  for (int i = 1; i < amount + 1; i++) {
    amounts[i] = INT_MAX;
  }
  for (int i = 0; i <= amount; ++i) {
    if (amounts[i] != INT_MAX) {
      for (id coin in coins) {
        if (i + [coin intValue] <= amount) {
          amounts[i + [coin intValue]] = MIN(amounts[i + [coin intValue]], amounts[i] + 1);
        }
      }
    }
  }
  return amounts[amount] == INT_MAX ? -1 : amounts[amount];
}