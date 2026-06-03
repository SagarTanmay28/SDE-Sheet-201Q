1) Preorder 

// Recursion 

class Solution {
public:
    void preorder(TreeNode* root, vector<int> &ans){
        if(root == NULL) return; // Base Case
        ans.push_back(root->val); // Kaam 
        preorder(root->left,ans); // Call 1
        preorder(root->right,ans); // Call 2
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root,ans);
        return ans;
    }
};

// Iterative 

class Solution { // Iterative 
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if(root != NULL) st.push(root);
        while(st.size()>0){
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->right != NULL) st.push(temp->right);
            if(temp->left != NULL) st.push(temp->left);
        }
        return ans;
        
    }
};


2) Inorder

// Recursion 

class Solution {
public:
    void inorder(TreeNode* root, vector<int> &ans){
        if(root == NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return ans;  
    }
};

// Iterative 

class Solution { // Iterative 
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(st.size()>0 || node != NULL){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{ // node is NULL
                TreeNode* temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                node = temp->right;
            }
        }
        return ans;
        
    }
};


3) Postorder

// Recursion 

class Solution {
public:
    void postorder(TreeNode* root, vector<int> &ans){
        if(root == NULL) return;
        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root,ans);
        return ans;
        
    }
};

// Iterative 

class Solution { //Iterative 
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if(root != NULL) st.push(root);
        while(st.size()>0){
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->left != NULL) st.push(temp->left);
            if(temp->right != NULL) st.push(temp->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
