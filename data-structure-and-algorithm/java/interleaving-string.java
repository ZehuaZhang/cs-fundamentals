/**
 * Interleaving String
 * 
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 * 
 * For example,
 * Given:
 * s1 = "aabcc",
 * s2 = "dbbca",
 * 
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
 */

public class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1 == null || s2 == null || s3 == null) {
            throw new NullPointerException();
        }

        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }

        boolean[][] canFormedByInterleave = new boolean[s1.length() + 1][s2.length() + 1];
        canFormedByInterleave[0][0] = true;

        for (int i = 1; i <= s1.length(); ++i) {
            canFormedByInterleave[i][0] = canFormedByInterleave[i - 1][0] && (s1.charAt(i - 1) == s3.charAt(i - 1));
        }

        for (int j = 1; j <= s2.length(); ++j) {
            canFormedByInterleave[0][j] = canFormedByInterleave[0][j - 1] && (s2.charAt(j - 1) == s3.charAt(j - 1));
        }

        for (int i = 1; i <= s1.length(); ++i) {
            for (int j = 1; j <= s2.length(); ++j) {
                canFormedByInterleave[i][j] =
                    (canFormedByInterleave[i - 1][j] && (s1.charAt(i - 1) == s3.charAt(i + j - 1))) ||
                    (canFormedByInterleave[i][j - 1] && (s2.charAt(j - 1) == s3.charAt(i + j - 1)));
            }
        }

        return canFormedByInterleave[s1.length()][s2.length()];
    }
}
