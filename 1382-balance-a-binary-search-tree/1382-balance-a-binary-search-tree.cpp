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
    vector<int> A;
    TreeNode* helper(int low, int high){
        if(low > high) return NULL;
        int mid = low + (high - low) / 2;
        TreeNode* node = new TreeNode(A[mid]);
        node -> left = helper(low, mid - 1);
        node -> right = helper(mid + 1, high);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return helper(0, A.size() - 1);
    }
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root -> left);
        A.push_back(root -> val);
        inorder(root -> right);
    }
};