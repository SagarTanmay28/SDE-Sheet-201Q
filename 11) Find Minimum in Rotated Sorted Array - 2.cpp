class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        int ans = INT_MAX;
        while (lo <= hi) {
            // Skip duplicates at the beginning
            while (lo < hi && nums[lo] == nums[lo + 1]) {
                lo++;
            }
            // Skip duplicates at the end
            while (lo < hi && nums[hi] == nums[hi - 1]) {
                hi--;
            }

            int mid = lo + (hi - lo) / 2;
            

            if (nums[lo] <= nums[mid]) {
                // Left part is sorted
                ans = min(ans, nums[lo]);
                lo = mid + 1;
            } else {
                // Right part is sorted
                ans = min(ans, nums[mid]);
                hi = mid - 1;
            }
        }

        return ans;
    }
}; // https://chatgpt.com/c/6754865b-f140-8000-9c9b-1c5d33a554e2
