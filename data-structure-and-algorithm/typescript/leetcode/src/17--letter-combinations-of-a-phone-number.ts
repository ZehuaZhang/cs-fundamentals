/*
17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

function letterCombinations(digits: string): string[] {
  const map = [
    "_",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz",
  ];
  const n = digits.length;

  const rslt: string[] = [];
  const path: string[] = [];
  dfs(0);

  return rslt.filter(Boolean);

  function dfs(i: number) {
    if (i === n) {
      rslt.push(path.join(""));
      return;
    }
    const d = Number(digits[i]);
    for (const c of map[d]) {
      path.push(c);
      dfs(i + 1);
      path.pop();
    }
  }
}
