;
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void getSub(vector<int>& nums, int index, int n) {
        if (index == n) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        getSub(nums, index + 1, n);
        // delete last elment
        curr.pop_back();
        // backtrack
        getSub(nums, index + 1, n);
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size();
        getSub(nums, 0, n);
        return ans;
    }
};