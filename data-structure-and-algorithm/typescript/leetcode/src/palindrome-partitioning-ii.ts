/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.



Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1


Constraints:

1 <= s.length <= 2000
s consists of lower-case English letters only.
*/

function minCut(s) {
  const result = [...Array(s.length + 1)].map((_, i) => i - 1);
  for (let i = 0; i < s.length; ++i) {
    // odd length
    for (
      let j = 0;
      i - j >= 0 && i + j < s.length && s[i - j] === s[i + j];
      ++j
    ) {
      result[i + j + 1] = Math.min(result[i + j + 1], 1 + result[i - j]);
    }

    // even length
    for (
      let j = 1;
      i - j + 1 >= 0 && i + j < s.length && s[i - j + 1] === s[i + j];
      ++j
    ) {
      result[i + j + 1] = Math.min(result[i + j + 1], 1 + result[i - j + 1]);
    }
  }
  return result[s.length];
}
