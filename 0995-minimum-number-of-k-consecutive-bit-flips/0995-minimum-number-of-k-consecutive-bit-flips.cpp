class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                cnt++;
            }
        }
  
        if (cnt == 0) {
            return 0;
        }

        // if (cnt < k) {
        //     return -1;
        // }
        
        if(k == 1)return cnt;

        cnt = 0; 
        
        for (int i = 0; i <= n - k; i++) {
            if (nums[i] == 0) {
                cnt++;
                for (int j = 0; j < k; j++) {
                    nums[i + j] = 1 - nums[i + j];
                }
            }
        }

        // Check if there are any zeros left in the remaining part of the array
        for (int i = n - k + 1; i < n; i++) {
            if (nums[i] == 0) {
                return -1;
            }
        }

        return cnt;
    }
};
