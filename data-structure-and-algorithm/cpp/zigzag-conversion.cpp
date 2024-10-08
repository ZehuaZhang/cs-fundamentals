// 6. ZigZag Conversion
// Difficulty: Easy

// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
// (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"

// Time:  O(n)
// Space: O(1)

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    const int step = 2 * numRows - 2;
    string zigzag;
    for (int i = 0; i < numRows; ++i) {
      for (int j = i; j < s.length(); j += step) {
        zigzag.push_back(s[j]);
        if (i > 0 && i < numRows - 1 && j + step - 2 * i < s.length()) {    
          zigzag.push_back(s[j + step - 2 * i]);
        }
      }
    }
    return zigzag;
  }
};
