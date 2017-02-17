// 347. Top K Frequent Elements
// Difficulty: Medium

// Given a non-empty array of integers, return the k most frequent elements.

// For example,
// Given [1,1,1,2,2,3] and k = 2, return [1,2].

// Note: 
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm time complexity must be better than O(n log n), where n is the array size.

// Time:  O(nlogk)
// Space: O(n)
// Heap solution.
class Solution2 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int i = 0; i < nums.size(); ++i) {
            ++counts[nums[i]];
        }
        priority_queue<pair<int, int>> heap;
        for (auto it = counts.begin(); it != counts.end(); ++it) {
            heap.emplace(-(it->second), it->first);
            if (heap.size() == k + 1) {
                heap.pop();
            }
        }
        vector<int> result;
        while (!heap.empty()) {
            result.emplace_back(heap.top().second);
            heap.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
