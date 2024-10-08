// 228. Summary Ranges
// Difficulty: Medium

// Given a sorted integer array without duplicates, return the summary of its ranges.

// For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

// Time:  O(n)
// Space: O(1)

class Solution {
public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ranges;
    if (nums.empty()) {
      return ranges;
    }

    for (int start = nums[0], end = nums[0], i = 1; i <= nums.size(); ++i) {
      if (i < nums.size() && nums[i] == end + 1) {
        end = nums[i];
      } else  {
        string range = to_string(start);
        if (start != end) {
          range.append("->" + to_string(end));
        }
        ranges.emplace_back(range);
        if (i < nums.size()) {
          start = end = nums[i];
        }
      }
    }
    return ranges;
  }
};
