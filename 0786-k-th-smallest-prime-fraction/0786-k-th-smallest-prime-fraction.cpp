#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // minheap
        priority_queue<pair<double, pair<int, int>>,
                       vector<pair<double, pair<int, int>>>,
                       greater<pair<double, pair<int, int>>>>
            pq;

        for (int i = 0; i < arr.size() - 1; i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                double fraction = (double)arr[i] / arr[j];
                pq.push({fraction, {arr[i], arr[j]}});
            }
        }

        while (--k) {
            pq.pop();
        }
        return vector<int>{pq.top().second.first, pq.top().second.second};
    }
};
