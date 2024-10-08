// 275. H-Index II
// Difficulty: Medium

// Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

// Hint:
// Expected runtime complexity is in O(log n) and the input is sorted.

// Time:  O(logn)
// Space: O(1)

class Solution {
public:
  int hIndex(vector<int>& citations) {
    const int n = citations.size();
    int left = 0, right = n - 1;
    while (left <= right) {
      const auto mid = left + (right - left) / 2;
      if (citations[mid] >= n - mid) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return n - left;
  }
};
