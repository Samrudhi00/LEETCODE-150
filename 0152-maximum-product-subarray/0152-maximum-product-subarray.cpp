class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int currMax = nums[0], currMin = nums[0], ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int temp = max({nums[i], currMax * nums[i], currMin * nums[i]});
            currMin = min({nums[i], currMax * nums[i], currMin * nums[i]});
            currMax = temp;

            ans = max(ans, currMax);
        }

        return ans;
    }
};