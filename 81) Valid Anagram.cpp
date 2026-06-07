class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        for(int i=0;i<s.size();i++){
            mp1[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            mp2[t[i]]++;
        }

        for(auto &x : mp2){
            char ch = x.first;
            int val = x.second;
            if(mp1.find(ch) != mp1.end()){
                if(mp1[ch] != val) return false;
            }
            else return false;
        }
        return true;
        
    }
};
