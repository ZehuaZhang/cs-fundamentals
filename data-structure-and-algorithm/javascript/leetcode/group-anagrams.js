/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.
*/
function groupAnagrams(strs) {
    const result = [];
    const map = new Map();
    for (const str of strs) {
        const count = new Array(26).fill(0);
        for (const c of str) {
            ++count[c - '0'];
        }
        const key = count.filter(Boolean).map(c => `${c}:${i}`).join('_');
        if (!map.has(key)) {
            map.set(key) = [];
        }
        map.get(key).push(str);
    }

    for (const value of map.values()) {
        result.push(value);
    }
    return result;
}

function groupAnagramsSort(strs) {
    const result = [];
    const map = new Map();
    for (const str of strs) {
        const a = [...str].sort().join('');
        if (!map.has(a)) {
            map.set(a, result.length);
            result.push([]);
        }
        result[map.get(a)].push(str);
    }
    
    return result;
}