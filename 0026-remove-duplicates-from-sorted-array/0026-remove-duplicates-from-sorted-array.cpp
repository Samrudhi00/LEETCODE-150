class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        if(n==0) return 0;
        int unique_index=0;
        for(int i=1;i<n;i++){
            if(nums[i] != nums[unique_index]){
                unique_index++;
                nums[unique_index]=nums[i];
            }
        }  
        int numOfElements = unique_index+1;
     return numOfElements;
    }
};
