class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        int n=nums.size()/2;

        for(auto a:nums){
            map[a]++;
        }
        int ans=0;
        for(auto a:map){
            if(a.second>n){
                ans=a.first;
            }
        }
        return ans;

    }
};