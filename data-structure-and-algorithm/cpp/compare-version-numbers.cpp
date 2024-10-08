// 165. Compare Version Numbers
// Difficulty: Easy

// Compare two version numbers version1 and version2.
// If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

// You may assume that the version strings are non-empty and contain only digits and the . character.
// The . character does not represent a decimal point and is used to separate number sequences.
// For instance, 2.5 is not "two and a half" or "half way to version three",
// it is the fifth second-level revision of the second first-level revision.

// Here is an example of version numbers ordering:

// 0.1 < 1.1 < 1.2 < 13.37

// Time:  O(n)
// Space: O(1)

class Solution {
public:
  int compareVersion(string version1, string version2) {
    const int n1 = version1.length(), n2 = version2.length();
    for (int i = 0, j = 0; i < n1 || j < n2; ++i, ++j) {
      int v1 = 0, v2 = 0;
      while (i < n1 && version1[i] != '.') {
        v1 = v1 * 10 + version1[i++] - '0';
      }
      while (j < n2 && version2[j] != '.') {
        v2 = v2 * 10 + version2[j++] - '0';
      }
      if (v1 != v2) {
        return v1 > v2 ? 1 : -1;
      }
    }
    return 0;
  }
};
