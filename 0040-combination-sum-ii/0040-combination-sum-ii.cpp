class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<int>& path,
                   vector<vector<int>>& ans, int start) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            path.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], path, ans, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(candidates, target, path, ans, 0);
        return ans;
    }
};
