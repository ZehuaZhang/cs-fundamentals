/**
 * Compare Version Numbers
 * 
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1; if version1 <version2 return -1;otherwise return 0.
 * 
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 * The . character does not represent a decimal point and is used to separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
 * 
 * Example 1:
 * 
 * Input: version1 = "0.1", version2 = "1.1"
 * Output: -1
 * Example 2:
 * 
 * Input: version1 = "1.0.1", version2 = "1"
 * Output: 1
 * Example 3:
 * 
 * Input: version1 = "7.5.2.4", version2 = "7.5.3"
 * Output: -1
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
 */

public class Solution {
    public int compareVersion(String version1, String version2) {
        for (int index1 = 0, index2 = 0; index1 < version1.length() || index2 < version2.length(); ++index1, ++index2) {
            int subVersion1 = 0;
            while (index1 < version1.length() && version1.charAt(index1) != '.') {
                subVersion1 = 10 * subVersion1 + version1.charAt(index1++) - '0';
            }

            int subVersion2 = 0;
            while (index2 < version2.length() && version2.charAt(index2) != '.') {
                subVersion2 = 10 * subVersion2 + version2.charAt(index2++) - '0'; 
            }

            if (subVersion1 != subVersion2) {
                return subVersion1 > subVersion2 ? 1 : -1;
            }
        }

        return 0;
    }
}
