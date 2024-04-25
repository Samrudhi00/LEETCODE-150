class Solution {
public:
    int arrangeCoins(int n) {
        long long n_long = n;
        int left = 1;
        int right = n_long;
        int ans;
        while(left <=  right){
            int mid = left + (right - left) / 2;
            long long sum = (long long)mid * (mid + 1) / 2;
            if(sum  <= n_long){
                left = mid+1;

            }else{
                right = mid-1;
                
            }

        }
        return left-1;
        // int i=1;
        // while (n>=i) {
        //     n-=i;
        //     i++;
        // }

        // return --i;
    }
};