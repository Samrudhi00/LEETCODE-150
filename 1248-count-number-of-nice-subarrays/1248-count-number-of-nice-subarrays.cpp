class Solution {
public:
    int solve(vector<int>& nums, int k) {
        if (k < 0) {
            return 0;
        }
        int left = 0;
        int right = 0;
        int odd_cnt = 0;
        int ans = 0;

        while (right < nums.size()) {
            if (nums[right] % 2 == 1) {
                odd_cnt++;
            }
            while (odd_cnt > k) {
                if (nums[left] % 2 == 1) {
                    odd_cnt--;
                }
                left++;
            }
            ans += right - left + 1;
            right++;
        }

        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};