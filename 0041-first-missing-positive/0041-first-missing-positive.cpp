#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int x=nums[i];
            while(x>=1 && x <= n && x!=i+1 && nums[x-1]!=x){
                swap(nums[x-1],nums[i]);
                x=nums[i];
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i] == i+1)continue;
            return i+1;
        }
        return n+1;

       


        /////////////////////////////////////////////////////////////
        // int n = nums.size();
        // unordered_set<int> seen;
        // // Mark presence of positive integers in the array
        // for (int num : nums) {
        //     if (num > 0)
        //         seen.insert(num);
        // }
        // // Find the smallest missing positive integer
        // for (int i = 1; i <= n; ++i) {
        //     if (seen.find(i) == seen.end()) {
        //         return i;
        //     }
        // }

        // If all positive integers from 1 to n are present, return n+1
        return n + 1;

         /////////////////////////////////////////////////////////////

        // unordered_set<int> ispresent(nums.begin(), nums.end());
        
        // int smallestPositive = 1;
        // while (ispresent.find(smallestPositive) != ispresent.end()) {
        //     cout<<smallestPositive;
        //     smallestPositive++;
            
        // }
        
        // return smallestPositive;
    }
};
