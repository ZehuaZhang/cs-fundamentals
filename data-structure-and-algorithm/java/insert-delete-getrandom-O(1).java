/**
 * Insert Delete GetRandom O(1)
 * 
 * Design a data structure that supports all following operations in average O(1) time.
 * 
 * insert(val): Inserts an item val to the set if not already present.
 * remove(val): Removes an item val from the set if present.
 * getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
 *  
 * 
 * Example:
 * 
 * // Init an empty set.
 * RandomizedSet randomSet = new RandomizedSet();
 * 
 * // Inserts 1 to the set. Returns true as 1 was inserted successfully.
 * randomSet.insert(1);
 * 
 * // Returns false as 2 does not exist in the set.
 * randomSet.remove(2);
 * 
 * // Inserts 2 to the set, returns true. Set now contains [1,2].
 * randomSet.insert(2);
 * 
 * // getRandom should return either 1 or 2 randomly.
 * randomSet.getRandom();
 * 
 * // Removes 1 from the set, returns true. Set now contains [2].
 * randomSet.remove(1);
 * 
 * // 2 was already in the set, so return false.
 * randomSet.insert(2);
 * 
 * // Since 1 is the only number in the set, getRandom always return 1.
 * randomSet.getRandom();
 */

import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Stack;
import java.util.ArrayList;
import java.util.HashMap;

public class RandomizedSet {
    RandomizedSet() {
        numbers = new ArrayList<>();
        indexMap = new HashMap<>();
    }
        
    public boolean insert(int val) {
        if (indexMap.containsKey(val)) {
            return false;
        }

        indexMap.put(val, numbers.size());
        numbers.add(val);

        return true;
    }
    
    public boolean remove(int val) {
        if (!indexMap.containsKey(val)) {
            return false;
        }

        int lastEntryVal = numbers.get(numbers.size() - 1);
        int lastEntryIndex = indexMap.get(lastEntryVal);
        int index = indexMap.get(val);

        numbers.set(index, lastEntryVal);
        indexMap.put(lastEntryVal, index);

        numbers.remove(numbers.size() - 1);
        indexMap.remove(val);

        return true;
    }
    
    int getRandom() {
        Random random = new Random();
        return numbers.get(random.nextInt(numbers.size()));
    }

    private List<Integer> numbers;
    private Map<Integer, Integer> indexMap;
}