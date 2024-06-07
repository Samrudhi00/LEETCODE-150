class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> subsequenceEnds(nums.size(), 0);
        int currentLength = 0;

        for (int num : nums) {
            int left = 0, right = currentLength;
            while (left != right) {
                int mid = (left + right) / 2;
                if (subsequenceEnds[mid] < num)
                    left = mid + 1;
                else
                    right = mid;
            }
            subsequenceEnds[left] = num;
            if (left == currentLength) ++currentLength;
        }
        return currentLength;
    }
};
