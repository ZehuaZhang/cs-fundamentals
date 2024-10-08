// 179. Largest Number
// Difficulty: Medium

// Given a list of non negative integers, arrange them such that they form the largest number.

// For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

// Note: The result may be very large, so you need to return a string instead of an integer.

// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
  string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [](const int &i, const int &j) {
      return to_string(i) + to_string(j) > to_string(j) + to_string(i);
    });

    string max;
    for (auto num : nums) {
      max.append(to_string(num));
    }
    return !max.empty() && max[0] == '0' ? "0" : max;
  }
};
