class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int,int>mp;
        // for(int i:nums){
        //     mp[i]++;
        // }
        // int max=nums[0];
        // for(auto x:mp){
        //     if(x.second>mp[max]){
        //         max=x.first;
        //     }
        // }
        // return max;

        //TL:O(n)   SC:O(n)

        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};