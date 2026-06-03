// ==========================
// LEFT SIDE VIEW OF BINARY TREE
// ==========================

// --------------------------------------------------
// 1. DFS (nth level approach)
// --------------------------------------------------
class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }
    
    void nthLevel(TreeNode* root, int curr, int level, vector<int> &ans){
        if(root == NULL) return;

        if(curr == level){
            ans[curr] = root->val;
            return;
        }

        // left first
        nthLevel(root->left, curr + 1, level, ans);
        nthLevel(root->right, curr + 1, level, ans);
    }

    void levelOrder(TreeNode* root, vector<int> &ans){
        int n = ans.size();

        for(int i = 0; i < n; i++){
            nthLevel(root, 0, i, ans);
        }
    }

    vector<int> leftSideView(TreeNode* root) {
        vector<int> ans(levels(root), 0);

        levelOrder(root, ans);

        return ans;
    }
};


// --------------------------------------------------
// 2. Preorder Traversal
// --------------------------------------------------
class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }
    
    void preorder(TreeNode* root, vector<int> &ans, int level){
        if(root == NULL) return;

        ans[level] = root->val;

        // right first so left overwrites
        preorder(root->right, ans, level + 1);
        preorder(root->left, ans, level + 1);
    }

    vector<int> leftSideView(TreeNode* root) {
        vector<int> ans(levels(root), 0);

        preorder(root, ans, 0);

        return ans;
    }
};


// --------------------------------------------------
// 3. More Clean DFS (Recommended)
// --------------------------------------------------
class Solution {
public:

    void dfs(TreeNode* root, vector<int>& ans, int level){

        if(root == NULL) return;

        // first node visited at this level
        if(level == ans.size()){
            ans.push_back(root->val);
        }

        // go left first
        dfs(root->left, ans, level + 1);

        // then right
        dfs(root->right, ans, level + 1);
    }

    vector<int> leftSideView(TreeNode* root) {

        vector<int> ans;

        dfs(root, ans, 0);

        return ans;
    }
};


// --------------------------------------------------
// 4. BFS (Level Order)
// --------------------------------------------------
class Solution {
public:
    vector<int> leftSideView(TreeNode* root) {

        vector<int> result;
        if(!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++){

                TreeNode* node = q.front();
                q.pop();

                // first node of level
                if(i == 0){
                    result.push_back(node->val);
                }

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        return result;
    }
};
