#include <vector>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int check,i,j;
        vector<int> v;
        for(i=0;i<nums.size();i++)
        {
          for(j=i+1;j<nums.size();j++)
          {
            check=nums[i]+nums[j];
            if(check == target)
            {
              v.push_back(i);
              v.push_back(j);
            }
          }
        }
      return v;
    }
};


