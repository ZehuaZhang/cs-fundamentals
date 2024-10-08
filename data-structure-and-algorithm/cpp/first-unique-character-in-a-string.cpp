// 387. First Unique Character in a String
// Difficulty: Easy

// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

// Examples:

// s = "leetcode"
// return 0.

// s = "loveleetcode",
// return 2.
// Note: You may assume the string contain only lowercase letters.

// Time:  O(n)
// Space: O(n)

class Solution {
public:
  int firstUniqChar(string s) {
    unordered_map<char, int> cnt;
    for (char c : s) {
      ++cnt[c];
    }
    for (int i = 0; i < s.size(); ++i) {
      if (cnt[s[i]] == 1) {
        return i;
      }
    }
    return -1;
  }
};

// Time:  O(n)
// Space: O(n)

// One-pass solution.
class Solution {
public:
  int firstUniqChar(string s) {
    using IT = list<int>::iterator;

    list<int> candidates;
    unordered_map<char, IT> lookup;
    for (int i = 0; i < s.length(); ++i) {
      const auto c = s[i];
      if (lookup.count(c)) {
        if (lookup[c] != candidates.end()) {
          candidates.erase(lookup[c]);
        }
        lookup[c] = candidates.end();
      } else {
        lookup[c] = candidates.emplace(candidates.end(), i);
      }
    }
    return candidates.empty() ? -1 : candidates.front();
  }
};