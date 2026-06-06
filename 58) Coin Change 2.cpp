You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1


// Recursion + Memoization - 1

class Solution {
public:
    int solve(int amount, vector<int>& coins, int i, long long sum, vector<vector<int>> &dp){
        int n = coins.size();
        
        if(sum > amount) return 0;
        if(i >= n) return sum == amount;

        if(dp[i][sum] != -1) return dp[i][sum];

        int take = solve(amount,coins,i,sum + coins[i],dp);
        int leave = solve(amount,coins,i+1,sum,dp);

        return dp[i][sum] = take + leave;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = solve(amount,coins,0,0LL,dp);

        return ans;
    }
};

// Recursion + Memoization - 2

class Solution {
public:
    int solve(int amount, vector<int>& coins, int i, vector<vector<int>>& dp){
        if(amount == 0) return 1;
        if(amount < 0 || i >= coins.size()) return 0;

        if(dp[i][amount] != -1) return dp[i][amount];

        int take = solve(amount-coins[i],coins,i,dp);
        int leave = solve(amount,coins,i+1,dp);

        return dp[i][amount] = take + leave;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(amount,coins,0,dp);
    }
};

// Bottom Up - 2D
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        
        // Base case
        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;   // amount = 0
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                
                if(coins[i-1] <= j) {
                    dp[i][j] = dp[i][j - coins[i-1]]  // Take
                               + dp[i-1][j];          // Leave
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][amount];
    }
};

// Bottom Up - 1D

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        
        for(int i = 0; i < coins.size(); i++) {
            for(int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        
        return dp[amount];
    }
};
