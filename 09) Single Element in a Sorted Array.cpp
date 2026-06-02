You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10



class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-2]!=nums[n-1]) return nums[n-1];
        int lo = 1;
        int hi = n-2;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            else if( (mid%2!=0 && nums[mid]==nums[mid-1] ) || (mid%2==0 && nums[mid]==nums[mid+1]) ) lo = mid + 1;
            else hi = mid - 1;
        }

        return -1;
        
    }
};


[1,1,2,2,3,4,4,5,5]
         ^
      single = 3

Look at indices:

Index:  0 1 2 3 4 5 6 7 8
Value: [1,1,2,2,3,4,4,5,5]
Before the single element

Pairs start at even index.

1,1 -> (0,1)
2,2 -> (2,3)

Pattern:

even index = first occurrence
odd index  = second occurrence

Example:

nums[0] == nums[1]
nums[2] == nums[3]
After the single element

Everything shifts by one.

4,4 -> (5,6)
5,5 -> (7,8)

Now:

odd index = first occurrence
even index = second occurrence

The pattern flips.

That’s why we use odd/even.

Case 1: mid is odd

Suppose:

Index: 0 1 2 3 4 5 6
Value: 1 1 2 2 3 4 4

Take:

mid = 3 (odd)
nums[3] = 2

Check:

nums[mid] == nums[mid-1]

Meaning:

2 == 2

This means the pair is correctly formed:

(2,3)

Since odd index matches left neighbor, we are still in the left valid region (before single).

So the single element must be on the right:

lo = mid + 1;
Case 2: mid is even

Example:

Index: 0 1 2 3 4 5 6
Value: 1 1 2 2 3 4 4

Take:

mid = 2 (even)
nums[2] = 2

Check:

nums[mid] == nums[mid+1]

Meaning:

2 == 2

Again, pair is correctly aligned:

(2,3)

We are before the single element.

So go right:

lo = mid + 1;
Combined condition

Your line:

(mid%2!=0 && nums[mid]==nums[mid-1]) ||
(mid%2==0 && nums[mid]==nums[mid+1])

means:

“Is mid following the normal pairing pattern?”

If YES:

single element is on the right

So:

lo = mid + 1;

Else:

pattern is broken
single lies on left side

So:

hi = mid - 1;
