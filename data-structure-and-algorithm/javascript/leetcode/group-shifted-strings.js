/*
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

Example:

Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Output: 
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
*/

function groupStrings(strs) {
    const map = new Map();
    for (const s of strs) {
        const hash = [...s]
            .map(c => 
                String.fromCharCode((c.charCodeAt() - s[0].charCodeAt() + 26) % 26 + 'a'.charCodeAt()))
            .join("");
        if (!map.has(hash)) {
            map.set(hash, new Set());
        }
        map.get(hash).add(s);
    }

    return [...map.values()].map(set => [...set].sort());
}