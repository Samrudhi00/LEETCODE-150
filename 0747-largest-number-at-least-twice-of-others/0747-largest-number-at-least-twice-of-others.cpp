class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int maxVal = INT_MIN;  
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxVal) { 
                maxVal = nums[i];
                index = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (maxVal < 2 * nums[i] && nums[i] != maxVal)  
                return -1;
        }

        return index;
    }
};
