/*
Merge two sorted (ascending) lists of interval and return it as a new sorted list. The new sorted list should be made by splicing together the intervals of the two lists and sorted in ascending order.
Example
Example1
Input: list1 = [(1,2),(3,4)] and list2 = [(2,3),(5,6)]
Output: [(1,4),(5,6)]
Explanation:
(1,2),(2,3),(3,4) --> (1,4)
(5,6) --> (5,6)
Example2
Input: list1 = [(1,2),(3,4)] and list2 = [(4,5),(6,7)]
Output: [(1,2),(3,5),(6,7)]
Explanation:
(1,2) --> (1,2)
(3,4),(4,5) --> (3,5)
(6,7) --> (6,7)
Notice
The intervals in the given list do not overlap.
The intervals in different lists may overlap.
*/

function mergeTwoInterval(list1, list2) {
    const result = [];
    let curr = null;
    for (let i = 0, j = 0; i < list1.length || j < list2.length;) {
        if (i === list1.length || list2[j][0] < list1[i][0]) {
            curr = merge(curr, list2[j], result);
            ++j;
        } else {
            curr = merge(curr, list1[i], result);
            ++i;
        }
    }
    result.push(curr);
    return result;
}

function merge(curr, next, result) {
    const [s, e] = curr || [NaN, NaN];
    const [s1, e1] = next;
    if (curr === null) {
        curr = next;
    } else if (e < s1) {
        result.push(curr);
        curr = next;
    } else {
        curr = [Math.min(s, s1), Math.max(e, e1)];
    }
    return curr;
}

console.log(mergeTwoInterval([[1,2],[3,4]], [[2,3],[5,6]]))