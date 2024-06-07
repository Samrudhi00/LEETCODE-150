#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;  
    void dfs(int i, vector<int>& curr, int total, vector<int>& candidates, int target) {
        if(total == target) {
            result.push_back(curr);  
            return;
        }
        if(i >= candidates.size() || total > target) {
            return;  
        }
        
        // Include the current candidate
        curr.push_back(candidates[i]);
        dfs(i, curr, total + candidates[i], candidates, target);
        curr.pop_back();
        // Exclude the current candidate and move to the next
        dfs(i + 1, curr, total, candidates, target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;  
        dfs(0, curr, 0, candidates, target);
        return result;
    }
};
