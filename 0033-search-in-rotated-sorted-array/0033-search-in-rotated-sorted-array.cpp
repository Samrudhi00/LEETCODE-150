#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int L = 0;
        int R = n - 1;

        while (L <= R) {
            int mid = L + (R - L) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] >= nums[L]) {
                if (target >= nums[L] && target < nums[mid]) {
                    R = mid - 1;
                } else {
                    L = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[R]) {
                    L = mid + 1;
                } else {
                    R = mid - 1;
                }
            }
        }
        return -1;
    }
};
