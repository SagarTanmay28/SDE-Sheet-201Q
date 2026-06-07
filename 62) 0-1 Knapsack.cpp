
Given two arrays, val[] and wt[], where each element represents the value and weight of an item respectively, and an integer W representing the maximum capacity of the knapsack (the total weight it can hold).

The task is to put the items into the knapsack such that the total value obtained is maximum without exceeding the capacity W.

Note: You can either include an item completely or exclude it entirely — fractional selection of items is not allowed. Each item is available only once.

Examples :

Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]
Output: 3
Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
Output: 0
Explanation: Every item has a weight exceeding the knapsack's capacity (3).
Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3] 
Output: 80
Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.

class Solution {
public:
    int solve(int i, int W, vector<int>& val, vector<int>& wt,
              vector<vector<int>>& dp) {

        // Base case
        if (i == 0 || W == 0)
            return 0;

        if (dp[i][W] != -1)
            return dp[i][W];

        // Not take current item
        int notTake = solve(i - 1, W, val, wt, dp);

        // Take current item
        int take = 0;
        if (wt[i - 1] <= W)
            take = val[i - 1] +
                   solve(i - 1, W - wt[i - 1], val, wt, dp);

        return dp[i][W] = max(take, notTake);
    }

    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();

        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

        return solve(n, W, val, wt, dp);
    }
};
