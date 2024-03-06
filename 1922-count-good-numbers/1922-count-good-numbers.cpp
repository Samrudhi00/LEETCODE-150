#define MOD 1000000007
class Solution {
public:
    long long power(long long x, long long y) {
        if (y == 0) return 1;
        if(y==1)return x;
        long long ans = power(x, y / 2) % MOD;
        ans = (ans * ans) % MOD;
        if (y % 2) {
            ans = (ans * x) % MOD;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long odd = n / 2;
        long long even = n / 2 + n % 2;  
        long long result = (power(5, even) * power(4, odd)) % MOD;
        return result;
    }
};