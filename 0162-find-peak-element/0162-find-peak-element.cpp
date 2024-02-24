class Solution {
public:
    int findPeakElement(vector<int>& nums) { 
        int max_ele = INT_MIN;
        int ans=0;
       for(int i=0;i<nums.size();i++){
          if(nums[i] > max_ele){
              max_ele = nums[i];
               ans=i;
          }
       }
       return ans;
    }
};