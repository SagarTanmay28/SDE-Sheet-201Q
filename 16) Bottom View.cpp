
class Solution {
public:
    vector<int> bottomView(Node *root) {

        vector<int> ans;
        if(root == NULL) return ans;

        // horizontal distance -> node value
        map<int, int> mp;

        // {node, horizontal distance}
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while(!q.empty()) {

            auto curr = q.front();
            q.pop();

            Node* node = curr.first;
            int hd = curr.second;

            // overwrite to keep bottom node
            mp[hd] = node->data;

            if(node->left) {
                q.push({node->left, hd - 1});
            }

            if(node->right) {
                q.push({node->right, hd + 1});
            }
        }

        // map keeps keys sorted
        for(auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
