Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]


class Solution {
public:
    void helper(vector<int>& nums, vector<int> ans,vector<vector<int> > &finalAns, int idx){
        if(idx==nums.size()){
            finalAns.push_back(ans);
            return;
        }
        helper(nums,ans,finalAns,idx+1);
        ans.push_back(nums[idx]);
        helper(nums,ans,finalAns,idx+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int> > finalAns;
        helper(nums,ans,finalAns,0);
        return finalAns;
        
    }
};
