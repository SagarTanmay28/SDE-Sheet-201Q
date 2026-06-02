You are given a 2D matrix mat[][] of size n x m. Each row in the matrix is sorted in non-decreasing order. Your task is to merge all the rows and return a single sorted array that contains all the elements of the matrix.

Examples :

Input: mat[][] = [[1, 3, 5, 7],
                [2, 4, 6, 8], 
                [0, 9, 10, 11]]
Output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
Explanation: Merging all elements from the 3 sorted arrays and sorting them results in: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11].
Input: mat[][] = [[1, 2, 3, 4], 
                [2, 2, 3, 4],
                [5, 5, 6, 6],
                [7, 8, 9, 9]]
Output: [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9] 
Explanation: Merging all elements from the 4 sorted arrays and sorting them results in:[1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9]
Constraints:
1 ≤ n * m ≤ 105
1 ≤ mat[i][j] ≤ 106

// Brute Force 

class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        vector<int> ans;
        
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans.push_back(mat[i][j]);
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

// Optimal 

class Solution {
public:

    typedef pair<int, pair<int,int>> p;

    vector<int> mergeArrays(vector<vector<int>> &mat) {

        int n = mat.size();
        int m = mat[0].size();

        priority_queue<p, vector<p>, greater<p>> pq;

        // push first element of every row
        for(int i = 0; i < n; i++) {
            pq.push({mat[i][0], {i, 0}});
        }

        vector<int> ans;

        while(!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int val = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;

            ans.push_back(val);

            // push next element from same row
            if(col + 1 < m) {
                pq.push({mat[row][col + 1], {row, col + 1}});
            }
        }

        return ans;
    }
};
