class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {difficulty[i], profit[i]};
        }
        sort(arr.begin(), arr.end());
        sort(worker.begin(), worker.end());

        int max_profit = 0, index = 0, best_profit = 0;

        for (int i = 0; i < worker.size(); i++) {
            while (index < n && worker[i] >= arr[index].first) {
                best_profit = max(best_profit, arr[index].second);
                index++;
            }
            max_profit += best_profit;
        }
        return max_profit;
    }
};
