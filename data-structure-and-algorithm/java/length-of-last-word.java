/**
 * Length of Last Word
 * 
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space characters only.
 * 
 * For example, 
 * Given s = "Hello World",
 * return 5.
 */

public class Solution {
    public int lengthOfLastWord(String s) {
        if (s == null) {
            throw new NullPointerException();
        }

        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s.charAt(i) != ' ') {
                if (i != 0 && s.charAt(i - 1) == ' ') {
                    result = 1;
                } else {
                    ++result;
                }
            }
        }

        return result;
    }
}