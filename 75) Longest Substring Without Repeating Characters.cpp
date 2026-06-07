Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_map<char,int> window; 
                                        
        int i = 0;
        int j = 0;
        int maxi = 0;
        // Sliding Window 
        while(j < n){
            window[s[j]]++;

            while(window.size() != (j-i+1)){
                window[s[i]]--;
                if(window[s[i]] == 0) window.erase(s[i]);
                i++;
            }

            maxi = max(maxi,j-i+1);
            j++;
        }

        return maxi;
    }
};
