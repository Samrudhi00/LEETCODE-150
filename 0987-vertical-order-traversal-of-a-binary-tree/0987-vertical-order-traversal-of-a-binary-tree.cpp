class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            map<int, vector<int>> levelNodes;  
            while (size--) {
                auto temp = q.front();
                q.pop();
                //we will crete dummy list
                TreeNode* node = temp.first;
                int hd = temp.second;
                levelNodes[hd].push_back(node->val); 
                if(node->left) {
                    q.push({node->left, hd - 1});
                }
                if(node->right) {
                    q.push({node->right, hd + 1});
                }
            }  
            for (auto& x : levelNodes) {
                sort(x.second.begin(), x.second.end()); 
                mp[x.first].insert(mp[x.first].end(), x.second.begin(), x.second.end());
            }
        }
        // Populate the result vector
        for (auto& x : mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};
