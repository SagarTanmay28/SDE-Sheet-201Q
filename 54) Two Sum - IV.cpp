class Solution {
public:
    bool check(TreeNode* root, int k, unordered_set<int>& st){
        if(root == NULL) return false;
        if(st.find(k - root->val) != st.end()) return true;
        st.insert(root->val);
        return check(root->left,k,st) || check(root->right,k,st);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return check(root,k,st);
    }
};
