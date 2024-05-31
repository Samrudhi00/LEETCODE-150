#include <vector>
#include <unordered_set>

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xor_all = 0;
        int xor_num = 0;
        for(int i=0;i<=n;i++){
           xor_all ^= i;
        }
        for(int num:nums){
            xor_num ^= num;

        }
        return xor_all ^ xor_num;

    }
};
