class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for (int num : nums) {
            mp[num] = true;
        }
        
        int n = nums.size();
        for (int i = 0; i <= n; ++i) {
            if (mp.find(i) == mp.end()) {
                return i;
            }
        }
        
        return -1; 
    }
};