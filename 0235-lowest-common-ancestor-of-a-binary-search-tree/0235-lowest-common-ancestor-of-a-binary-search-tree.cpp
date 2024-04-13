/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        // p is ancestor of q
        // q is ancestor of p
        if (root == p || root == q) {
            return root;
        }
        // p and q belong to diff subtree
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (p->val > curr->val && q->val > curr->val) {
                curr = curr->right;
            } else if (p->val < curr->val && q->val < curr->val) {
                curr = curr->left;
            } else {
                return curr; 
            }
        } 

        return nullptr; // p and q not found
    }
};