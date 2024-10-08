// 319. Bulb Switcher
// Difficulty: Medium

// There are n bulbs that are initially off. You first turn on all the bulbs.
// Then, you turn off every second bulb. On the third round, you toggle every third bulb
// (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb.
// For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

// Example:
// Given n = 3.

// At first, the three bulbs are [off, off, off].
// After first round, the three bulbs are [on, on, on].
// After second round, the three bulbs are [on, off, on].
// After third round, the three bulbs are [on, off, off].

// So you should return 1, because there is only one bulb is on.

// Time:  O(1)
// Space: O(1)

#import <Foundation/Foundation.h>

int bulbSwitch(int n) {
  // counts of on-state of n bulbs <=> counts of numbers (< n) with odd counts of factor pairs <=> counts of full squares.
  return (int)sqrt(n);
}