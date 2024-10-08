// 423. Reconstruct Original Digits from English
// Difficulty: Medium

// Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

// Note:
// Input contains only lowercase English letters.
// Input is guaranteed to be valid and can be transformed to its original digits.
// That means invalid inputs such as "abc" or "zerone" are not permitted.
// Input length is less than 50,000.
// Example 1:
// Input: "owoztneoer"

// Output: "012"
// Example 2:
// Input: "fviefuro"

// Output: "45"

// Time:  O(n)
// Space: O(1)

class Solution {
public:
  string originalDigits(string s) {
    const vector<string> numbers{ "zero", "one", "two", "three", "four",
                                  "five", "six", "seven", "eight", "nine" };
    vector<vector<int>> cnts(numbers.size(), vector<int>(26));
    for (int i = 0; i < numbers.size(); ++i) {
      for (const auto& c : numbers[i]) {
        ++cnts[i][c - 'a'];
      }
    }
    vector<int> order{0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    vector<char> unique_chars{'z', 'o', 'w', 't', 'u', 'f', 'x', 's', 'g', 'n'};
    vector<int> cnt(26);
    for (const auto& c : s) {
      ++cnt[c - 'a'];
    }

    string result;
    for (const auto& i : order) {
      while (cnt[unique_chars[i] - 'a'] > 0) {
        for (int j = 0; j < cnt.size(); ++j) {
          cnt[j] -= cnts[i][j];
        }
        result.push_back(i + '0');
      }
    }
    sort(result.begin(), result.end());
    return result;
  }
};