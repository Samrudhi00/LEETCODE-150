#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> ispresent(nums.begin(), nums.end());
        
        int smallestPositive = 1;
        while (ispresent.find(smallestPositive) != ispresent.end()) {
            cout<<smallestPositive;
            smallestPositive++;
            
        }
        
        return smallestPositive;
    }
};
