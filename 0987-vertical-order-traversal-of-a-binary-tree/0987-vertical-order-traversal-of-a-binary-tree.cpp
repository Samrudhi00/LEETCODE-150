class Solution {
public:
    void verticalTraversalRecursive(TreeNode* root, int index, int level, map<int, map<int, vector<int>>>& mp) {
        if (root == nullptr)
            return;
        
        mp[index][level].push_back(root->val);
        
        // left
        verticalTraversalRecursive(root->left, index - 1, level + 1, mp);
        // right
        verticalTraversalRecursive(root->right, index + 1, level + 1, mp);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        map<int, map<int, vector<int>>> mp;
        
        verticalTraversalRecursive(root, 0, 0, mp);
        
        // Populate the result vector
        for (auto& col : mp) {
            vector<int> column;
            for (auto& row : col.second) {
                // sort for indexes
                sort(row.second.begin(), row.second.end()); 
                //sort for level
                column.insert(column.end(), row.second.begin(), row.second.end());
            }
            ans.push_back(column);
        } 
        return ans;
    }
};
