class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n=prices[0];
        int cnt;
        sort(prices.begin(),prices.end());
        int total=prices[0]+prices[1];
        if(total <= money){
            int rem=money-total;
          return rem;
        }else{
            return money;
        }
    }
};