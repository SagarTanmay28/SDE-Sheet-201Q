You are given two integer arrays a[] and b[] of equal size. A sum combination is formed by adding one element from a[] and one from b[], using each index pair (i, j) at most once. Return the top k maximum sum combinations, sorted in non-increasing order.

Examples:

Input: a[] = [3, 2], b[] = [1, 4], k = 2
Output: [7, 6]
Explanation: Possible sums: 3 + 1 = 4, 3 + 4 = 7, 2 + 1 = 3, 2 + 4 = 6, Top 2 sums are 7 and 6.
Input: a[] = [1, 4, 2, 3], b[] = [2, 5, 1, 6], k = 3
Output: [10, 9, 9]
Explanation: The top 3 maximum possible sums are : 4 + 6 = 10, 3 + 6 = 9, and 4 + 5 = 9


// TLE 
class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size();
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum = a[i] + b[j];
                pq.push(sum);
                
                if(pq.size() > k) pq.pop();
            }
        }
        
        vector<int> ans;
        
        while(pq.size()){
            ans.push_back(pq.top());
            pq.pop();
        }
        
        sort(ans.begin(),ans.end(),greater<>());
        
        return ans;
    }
};

// Approach - 1 Accepted 
class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size();
        sort(a.begin(),a.end(),greater<>());
        sort(b.begin(),b.end(),greater<>());
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x = a[i];
                int y = b[j];
                
                if(pq.size() < k) pq.push(x+y);
                else if(pq.top() < x + y){
                    pq.pop();
                    pq.push(x+y);
                }
                else break; // VIMP
            }
        }
        
        vector<int> ans;
        
        while(pq.size()){
            ans.push_back(pq.top());
            pq.pop();
        }
        
        sort(ans.begin(),ans.end(),greater<>());
        
        return ans;
    }
};

// Approach - 2 Accepted 

class Solution {
  public:
    typedef pair<int,pair<int,int>> p;
    
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size();
        sort(a.begin(),a.end(),greater<>());
        sort(b.begin(),b.end(),greater<>());
        
        priority_queue<p> pq;
        
        int sum = a[0] + b[0];
        pq.push({sum,{0,0}});
        
        set<pair<int,int>> st;
        st.insert({0,0});
       
        
        vector<int> ans;
        
        while(k-- && pq.size() != 0){
            
            auto val = pq.top();
            pq.pop();
            
            int i = val.second.first;
            int j = val.second.second;
            
            ans.push_back(val.first);
            
            // check (i,j+1)
            if(j+1 < n && st.find({i,j+1}) == st.end()){
                pq.push({a[i] + b[j+1],{i,j+1}});
                st.insert({i,j+1});
            }
            
            // check (i+1,j)
            if(i+1 < n && st.find({i+1,j}) == st.end()){
                pq.push({a[i+1] + b[j],{i+1,j}});
                st.insert({i+1,j});
            }
        }
        
        
        sort(ans.begin(),ans.end(),greater<>());
        
        return ans;
    }
};
