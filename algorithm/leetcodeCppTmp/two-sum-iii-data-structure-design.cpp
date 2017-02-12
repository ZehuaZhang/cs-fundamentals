// 170. Two Sum III - Data structure design
// Difficulty : Easy

// Design and implement a TwoSum class. It should support the following operations:add and find.

// add - Add the number to an internal data structure.
// find - Find if there exists any pair of numbers which sum is equal to the value.

// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);

// For example,
// add(1); add(3); add(5);
// find(4) -> true
// find(7) -> false

// Time:  O(n)
// Space: O(n)

class TwoSum {
public:

    // Add the number to an internal data structure.
    void add(int number) {
        ++_lookup[number];
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        for (auto pair : _lookup) {
            int gap = value - pair.first;
            if (_lookup.count(gap) && (gap != pair.first || pair.second > 1)) {
                return true;
            }
        }
        return false;
    }

private:
    unordered_map<int, int> _lookup;
};
