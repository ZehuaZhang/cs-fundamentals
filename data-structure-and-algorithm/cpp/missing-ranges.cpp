// 163. Missing Ranges
// Difficulty: Medium

// Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.
// For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].

// Time:  O(n)
// Space: O(1)

class Solution {
public:
  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> ranges;
    for (int i = 0, pre = lower - 1, cur = 0; i <= nums.size(); ++i, pre = cur) {
      cur = i == nums.size() ? upper + 1 : nums[i];
    
      if (cur - pre >= 2) {
        ranges.emplace_back(getRange(pre + 1, cur - 1));
      }
    }
    return ranges;
  }

  string getRange(const int lower, const int upper) {
    return lower == upper ? to_string(lower) : to_string(lower) + "->" + to_string(upper);
  }
};
