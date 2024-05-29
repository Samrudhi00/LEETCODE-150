class Solution {
public:
    int hammingWeight(int n) {
        int ans=0;
        while(n){
            ans += n % 2;
            n = n>>1;
        }
        return ans;
        
    }
};