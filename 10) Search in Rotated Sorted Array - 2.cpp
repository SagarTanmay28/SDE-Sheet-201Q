class Solution {
public:
    bool search(vector<int>& nums, int k) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
    
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]==k) return true;
            if(nums[lo]==nums[mid] && nums[hi]==nums[mid]){
                lo++;
                hi--;
                continue;
            }
            // Left array is sorted 
            else if(nums[lo]<=nums[mid]){
                if(nums[lo]<=k && k<=nums[mid]) hi = mid - 1;
                else lo = mid + 1;
            }
            // Right array is sorted 
            else{
                if(nums[mid]<=k && k<=nums[hi]) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return false;
        
    }
};
