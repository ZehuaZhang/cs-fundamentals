// 412. Fizz Buzz
// Difficulty: Easy

// Write a program that outputs the string representation of numbers from 1 to n.

// But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”.
// For numbers which are multiples of both three and five output “FizzBuzz”.

// Example:

// n = 15,

// Return:
// [
//     "1",
//     "2",
//     "Fizz",
//     "4",
//     "Buzz",
//     "Fizz",
//     "7",
//     "8",
//     "Fizz",
//     "Buzz",
//     "11",
//     "Fizz",
//     "13",
//     "14",
//     "FizzBuzz"
// ]

// Time:  O(n)
// Space: O(1)

class Solution {
public:
  vector<string> fizzBuzz(int n) {
    vector<string> result;

    for (int i = 1; i <= n; ++i) {
      if (i % 15 == 0) {
        result.emplace_back("FizzBuzz");
      } else if (i % 5 == 0) {
        result.emplace_back("Buzz");
      } else if (i % 3 == 0) {
        result.emplace_back("Fizz");
      } else {
        result.emplace_back(to_string(i));
      }
    }
    return result;
  }
};