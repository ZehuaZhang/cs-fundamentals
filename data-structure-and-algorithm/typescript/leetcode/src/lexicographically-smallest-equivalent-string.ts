/*
1061. Lexicographically Smallest Equivalent String
Medium

You are given two strings of the same length s1 and s2 and a string baseStr.

We say s1[i] and s2[i] are equivalent characters.

For example, if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', and 'c' == 'e'.
Equivalent characters follow the usual rules of any equivalence relation:

Reflexivity: 'a' == 'a'.
Symmetry: 'a' == 'b' implies 'b' == 'a'.
Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.
For example, given the equivalency information from s1 = "abc" and s2 = "cde", "acd" and "aab" are equivalent strings of baseStr = "eed", and "aab" is the lexicographically smallest equivalent string of baseStr.

Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.



Example 1:

Input: s1 = "parker", s2 = "morris", baseStr = "parser"
Output: "makkek"
Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [m,p], [a,o], [k,r,s], [e,i].
The characters in each group are equivalent and sorted in lexicographical order.
So the answer is "makkek".
Example 2:

Input: s1 = "hello", s2 = "world", baseStr = "hold"
Output: "hdld"
Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [h,w], [d,e,o], [l,r].
So only the second letter 'o' in baseStr is changed to 'd', the answer is "hdld".
Example 3:

Input: s1 = "leetcode", s2 = "programs", baseStr = "sourcecode"
Output: "aauaaaaada"
Explanation: We group the equivalent characters in s1 and s2 as [a,o,e,r,s,c], [l,p], [g,t] and [d,m], thus all letters in baseStr except 'u' and 'd' are transformed to 'a', the answer is "aauaaaaada".


Constraints:

1 <= s1.length, s2.length, baseStr <= 1000
s1.length == s2.length
s1, s2, and baseStr consist of lowercase English letters.
*/

import {runTestCaseList} from './util/test';

function smallestEquivalentString(
  input1: string,
  input2: string,
  test: string
) {
  const baseCode = 'a'.charCodeAt(0);
  const repList = [...Array(26)].map((_, i) => i);

  for (let i = 0; i < input1.length; ++i) {
    union(input1[i], input2[i]);
  }

  const result: string[] = [];
  for (const char of test) {
    result.push(getCharFromIndex(find(char)));
  }

  return result.join('');

  function find(char: string): number {
    let idx = getRepIndex(char);
    while (idx !== repList[idx]) {
      idx = repList[idx];
    }
    return idx;
  }

  function union(char1: string, char2: string): void {
    const [idx1, idx2] = [char1, char2].map(char => find(char));
    if (idx1 !== idx2) {
      repList[Math.max(idx1, idx2)] = Math.min(idx1, idx2);
    }
  }

  function getRepIndex(text: string) {
    return text.charCodeAt(0) - baseCode;
  }

  function getCharFromIndex(index: number): string {
    return String.fromCharCode(index + baseCode);
  }
}

// tests

const testInputListCollection = [['leetcode', 'programs', 'sourcecode']];

const expectedResultList = ['aauaaaaada'];

runTestCaseList(
  testInputListCollection,
  expectedResultList,
  smallestEquivalentString
);
