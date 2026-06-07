Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".


class Solution {
public:
    int LCS(string& s, string& t, int i, int j, vector<vector<int>>& dp){

        if(i >= s.size() || j >= t.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]){
            return dp[i][j] = 1 + LCS(s,t,i+1,j+1,dp);
        }
        else{
            int first = LCS(s,t,i+1,j,dp);
            int second = LCS(s,t,i,j+1,dp);
            return dp[i][j] = max(first,second);
        }

    }
    int minInsertions(string s) {

        string t = s;
        reverse(t.begin(),t.end());

        int n = s.size();
        
        vector<vector<int>> dp(n,vector<int>(n,-1));

        int length = LCS(s,t,0,0,dp);

        return (n - length);
        
    }
};
