You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1
 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000


class Solution { // Learning -> Offset 
public:
    int solve(int i, int sum, vector<int>& nums, int target, vector<vector<int>>& dp){
        if(i >= nums.size()){
            return (sum == target);
        }

        if(dp[i][sum + 1000] != -1) return dp[i][sum + 1000];
        
        int take_positive = solve(i+1,sum + nums[i],nums,target,dp);
        int take_negative = solve(i+1,sum - nums[i],nums,target,dp);

        return dp[i][sum + 1000] = take_positive + take_negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<vector<int>> dp(n+1,vector<int>(2001,-1));
        return solve(0,0,nums,target,dp);
    }
};
