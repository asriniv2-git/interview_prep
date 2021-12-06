/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
Example 4:

Input: coins = [1], amount = 1
Output: 1
Example 5:

Input: coins = [1], amount = 2
Output: 2 */

// Hint - Bottom up approach, compute number of coins for every value between 1 and "amount". Refer https://www.youtube.com/watch?v=H9bfqozjoqs for full details.

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1); //Initialise to amount+1 (invalid) because the maximum number of coins is "amount" since no denomination less than 1
        int i, j;
        
        dp[0] = 0;
        
        for (i = 1; i <= amount; i++) {
            for (j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }
        
        if (dp[amount] != (amount+1)) {
            return dp[amount];
        }
        else {
            return -1;
        }
    }
};
