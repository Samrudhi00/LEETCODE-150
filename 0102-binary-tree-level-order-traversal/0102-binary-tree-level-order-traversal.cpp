/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void AddChildren(TreeNode* root, vector<vector<int>>& nodes, int level)
    {
        if(!root) return;
        if(level >= nodes.size())
        nodes.push_back({});
        
        nodes[level].push_back(root->val);
        AddChildren(root->left, nodes, level + 1);
        AddChildren(root->right, nodes, level + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        AddChildren(root, ans, 0);
        return ans;    
    }
};