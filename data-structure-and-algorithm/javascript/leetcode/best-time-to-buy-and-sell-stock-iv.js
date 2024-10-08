/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

0 <= k <= 100
0 <= prices.length <= 1000
0 <= prices[i] <= 1000
*/

function maxProfit(k, prices) {
    if (k >= prices.length) {
        return maxBestProfit(prices);
    }
    
    const result = Array(k + 1).fill(0);
    const curr = Array(k + 1).fill(0);
    for (let i = 0; i < prices.length - 1; ++i) {
        const diff = prices[i + 1] - prices[i];
        for (let j = k; j >= 1; --j) {
            curr[j] = Math.max(result[j - 1] + Math.max(diff, 0), curr[j] + diff);
            result[j] = Math.max(result[j], curr[j]);
        }
    }
    return result[k];
}

function maxBestProfit(prices) {
    let result = 0;
    for (let i = 1; i < prices.length; ++i) {
        if (prices[i] - prices[i - 1] > 0) {
            result += prices[i] - prices[i - 1];
        }
    }
    return result;
}