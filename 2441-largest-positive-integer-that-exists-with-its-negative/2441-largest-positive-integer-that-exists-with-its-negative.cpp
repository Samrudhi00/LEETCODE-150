class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int max_element = -1;
        unordered_set<int> mp(nums.begin(), nums.end());
        for (int num : nums) {
            if (mp.find(-num) != mp.end()) {
                max_element = max(max_element, num);
            }
        }
        return max_element;
    }
};
