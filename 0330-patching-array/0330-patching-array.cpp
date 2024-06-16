class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long cnt=0;
        long long total=0;
        long long i=0;
        while(total < n){
            if(i<nums.size() && nums[i] <= (total+1)){
                total += nums[i++];
            }else{
                cnt++;
                total += total+1;
            }
        }
        return cnt;
    }
};