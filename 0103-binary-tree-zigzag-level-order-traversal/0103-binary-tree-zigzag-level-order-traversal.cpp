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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;

        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;

            for (int i = 0; i < n; i++) {
                temp.push_back(q.front()->val);

                if (q.front()->left != nullptr) {
                    q.push(q.front()->left);
                }
                if (q.front()->right != nullptr) {
                    q.push(q.front()->right);
                }

                q.pop(); // Pop the processed node
            }
            if (!flag) {
                reverse(temp.begin(), temp.end());
            }
            // Push into final list
            ans.push_back(temp);
            flag = !flag;
        }
        return ans;
    }
};
