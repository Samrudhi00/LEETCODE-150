/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* node = root;
        if (node == NULL)
            return node;
        if (node->left != NULL || node->right != NULL) {
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
        }
        invertTree(node->left);
        invertTree(node->right);
        return root;
    }
};