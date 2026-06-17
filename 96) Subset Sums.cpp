Given an array arr of integers, return the sums of all subsets in the list.  Return the sums in any order.

Examples:

Input: arr[] = [2, 3]
Output: [0, 2, 3, 5]
Explanation: When no elements are taken then Sum = 0. When only 2 is taken then Sum = 2. When only 3 is taken then Sum = 3. When elements 2 and 3 are taken then Sum = 2+3 = 5.
Input: arr[] = [1, 2, 1]
Output: [0, 1, 1, 2, 2, 3, 3, 4]
Explanation: The possible subset sums are 0 (no elements), 1 (either of the 1's), 2 (the element 2), and their combinations.
Input: arr[] = [5, 6, 7]
Output: [0, 5, 6, 7, 11, 12, 13, 18]
Explanation: The possible subset sums are 0 (no elements), 5, 6, 7, and their combinations.

class Solution {
  public:
    void helper(vector<int>& nums, vector<int>& ans, int idx, int sum){
        if(idx == nums.size()){
            ans.push_back(sum);
            return;
        }
        helper(nums,ans,idx+1,sum);
        sum += nums[idx];
        helper(nums,ans,idx+1,sum);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        vector<int> ans;
        helper(arr,ans,0,0);
        return ans;
    }
};
