class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double sum = 0;
        int n = customers.size();
        int current = 0;
        for(int i = 0;i < n ; i++)
        {
            if(current < customers[i][0])
                current = customers[i][0];
            current += customers[i][1];
            sum += (current - customers[i][0]);  
        }
        return sum/n;
        
    }
};


