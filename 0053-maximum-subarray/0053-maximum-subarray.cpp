class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (currSum < 0) {
                currSum = 0;
            }
            currSum += nums[i];
            maxi = max(maxi, currSum);
        }
        return maxi;
    }
};