class Solution {
public:
    long long sumNums(vector<int>& nums){
        long long total=0;
        for(auto i:nums) total+=i;
        return total;
    }
    long long largestPerimeter(vector<int>& nums) {
        int n= nums.size();
       sort(nums.begin(),nums.end());
       long long total =sumNums(nums); 
       for(int i=n-1;i>=2;i--){
           if(total-nums[i]>nums[i])return total;
           total-=nums[i];
       }
    return -1;
    }

};