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
    bool evaluateTree(TreeNode* root) {
        //leaf cheak
        if(root->left == nullptr && root->right == nullptr){
            if(root->val == 0){
                return false;
            }
            return true;
        }

        bool leftTree = evaluateTree(root->left);
        bool rightTree = evaluateTree(root->right);
        if(root->val == 2){
            return leftTree || rightTree;
        }
        return leftTree && rightTree;
    }
};