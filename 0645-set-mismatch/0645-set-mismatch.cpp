class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result(2, 0);
        for(int i:nums){
            if(nums[abs(i)-1]<0){
                result[0]=abs(i);
            }else{
                nums[abs(i)-1] *= -1;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                result[1]=i+1;
                break;
            }
        }
        return result;
    }
};