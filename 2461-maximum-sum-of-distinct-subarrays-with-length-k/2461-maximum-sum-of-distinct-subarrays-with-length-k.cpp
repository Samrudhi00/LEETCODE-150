class Solution {
public:
    long long maximumSubarraySum(std::vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        long long maxSum = 0, currentSum = 0;
        std::unordered_set<int> windowSet;

        while (j < n) {
            while (windowSet.count(nums[j])) {
                windowSet.erase(nums[i]);
                currentSum -= nums[i];
                i++;
            }

            windowSet.insert(nums[j]);
            currentSum += nums[j];

            if (j - i + 1 == k) {
                maxSum = std::max(maxSum, currentSum);
                windowSet.erase(nums[i]);
                currentSum -= nums[i];
                i++;
            }

            j++;
        }

        return maxSum;
    }
};
