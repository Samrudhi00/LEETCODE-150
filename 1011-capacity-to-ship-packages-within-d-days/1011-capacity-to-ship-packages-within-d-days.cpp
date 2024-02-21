class Solution {
public:
    int daysRequired(vector<int>& weights, int capacity) {
        int x = 0, days = 1, index = 0;
        int n = weights.size();
        
        for (int i = 0; i < n; i++) {
            if (x + weights[i] <= capacity) {
                x += weights[i];
                index = i;
            } else {
                x = weights[i];
                index = i;
                days++;
            }
        }
        
        return days ;  
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int max_element = 0, sum = 0;

        for (int i = 0; i < n; i++) {
            if (max_element < weights[i]) {
                max_element = weights[i];
            }
            sum += weights[i];
        }

        int low = max_element;
        int high = sum;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (daysRequired(weights, mid) <= days) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
