/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
*/

/**
 * @param { string[] } strs
 * @return { string }
 */
function longestCommonPrefix(s) {
    let result = ""

    for (let j = 0; j < s[0].length; ++j) {
        for (let i = 1; i < s.length; ++i) {
            if (s[i][j] !== s[0][j]) {
                return result
            }
        }
        result += s[0][j]
    }
    
    return result
}