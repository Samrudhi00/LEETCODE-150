class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n= profit.size();
        vector<int2>arr(n);
        for(int i=0;i<n;i++){
            arr[i]= {diiiculty[i],profit[i]};
        }
        sort(arr.begin(),arr.end());
        sort(worker.begin(),worker.end());

        int mx_profit = 0,index=0,best_Profit=0;
        
    }
};