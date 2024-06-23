class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> mx_dq; 
        deque<int> min_dq; 
        int left = 0;
        int mx_Length = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (!mx_dq.empty() && nums[mx_dq.back()] <= nums[right]) {
                mx_dq.pop_back();
            }
            mx_dq.push_back(right);

            while (!min_dq.empty() && nums[min_dq.back()] >= nums[right]) {
                min_dq.pop_back();
            }
            min_dq.push_back(right);

            while (nums[mx_dq.front()] - nums[min_dq.front()] > limit) {
                ++left;
                if (mx_dq.front() < left) {
                    mx_dq.pop_front();
                }
                if (min_dq.front() < left) {
                    min_dq.pop_front();
                }
            }

            mx_Length = max(mx_Length, right - left + 1);
        }

        return mx_Length;
    }
};
