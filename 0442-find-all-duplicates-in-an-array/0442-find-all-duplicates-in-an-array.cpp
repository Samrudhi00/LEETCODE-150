class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for (auto i = mp.begin(); i != mp.end(); i++) {
            if (i->second > 1) {
                ans.push_back(i->first);
            }
        }
        // for (const auto& pair : mp) {
        //     if (pair.second > 1) {
        //         ans.push_back(pair.first);
        //     }
        // }

        return ans;
    }
};