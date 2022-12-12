/*
Given a string s, return the first non-repeating character in it and return its index. If it does not exist, return -1.



Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1


Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.
*/

function firstUniqChar(input: string): number {
  const map = new Map<string, number>();
  const set = new Set<string>();
  for (let i = 0; i < input.length; ++i) {
    const c = input[i];
    if (set.has(c)) {
      map.delete(c);
    } else {
      map.set(c, i);
      set.add(c);
    }
  }

  return map.size ? map.values().next().value : -1;
}
