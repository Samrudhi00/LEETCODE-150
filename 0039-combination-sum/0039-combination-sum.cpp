class Solution {
public:
    void togetcobinations(int index, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& curr) {
        // Base case
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] <= target) { // Change < to <= to include candidates equal to target
                curr.push_back(candidates[i]);
                togetcobinations(i, target - candidates[i], candidates, ans, curr);
                // Backtrack
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        togetcobinations(0, target, candidates, ans, curr);
        return ans;
    }
};
