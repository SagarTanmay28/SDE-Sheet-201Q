 class Solution {
  public:
    int solve(Node* root){
        if(root == NULL) return 1;
        if(root->left == NULL && root->right == NULL) return 1;
        
        int leftSum = 0;
        int rightSum = 0;
        
        if(root->left) leftSum = root->left->data;
        if(root->right) rightSum = root->right->data;
        
        return (root->data == leftSum + rightSum) && (solve(root->left) && solve(root->right));
    }
    bool isSumProperty(Node *root) {
        // code here
        return solve(root);
    }
};
