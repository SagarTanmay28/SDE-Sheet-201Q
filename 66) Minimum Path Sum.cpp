class Solution {
public:
    
    int minSum(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        if(r==n-1 && c==m-1) return grid[r][c];
        if(r==n || c==m) return INT_MAX;
        if(dp[r][c] != -1) return dp[r][c];
        return dp[r][c] = grid[r][c] + min(minSum(grid,r,c+1,dp),minSum(grid,r+1,c,dp));

    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return minSum(grid,0,0,dp);
        
    }
};
