#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

       


        /////////////////////////////////////////////////////////////
        int n = nums.size();
        unordered_set<int> seen;
        // Mark presence of positive integers in the array
        for (int num : nums) {
            if (num > 0)
                seen.insert(num);
        }
        // Find the smallest missing positive integer
        for (int i = 1; i <= n; ++i) {
            if (seen.find(i) == seen.end()) {
                return i;
            }
        }

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
