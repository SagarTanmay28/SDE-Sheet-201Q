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

// Recursion + Memoization 

class Solution {
public:
    int helper(vector<int>& coins, int amount, int i, long long sum, vector<vector<int>>& dp){
        if(sum == amount) return 0;
        if(sum > amount || i >= coins.size()) return INT_MAX;

        if(dp[i][sum] != -1) return dp[i][sum];

        int take = helper(coins,amount,i,sum+coins[i],dp);
        if(take != INT_MAX) take = take + 1;

        int leave = helper(coins,amount,i+1,sum,dp);

        return dp[i][sum] = min(take,leave);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        int ans = helper(coins,amount,0,0LL,dp);

        return (ans == INT_MAX) ? -1 : ans;
        
    }
};

// Bottom Up 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        const int INF = 1e9;
        
        vector<vector<int>> dp(n+1, vector<int>(amount+1, INF));
        
        // Base case
        for(int i = 0; i <= n; i++)
            dp[i][0] = 0;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                
                if(coins[i-1] <= j) {
                    dp[i][j] = min(
                        1 + dp[i][j - coins[i-1]],  // Take (same row)
                        dp[i-1][j]                  // Leave
                    );
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return (dp[n][amount] >= INF) ? -1 : dp[n][amount];
    }
};
