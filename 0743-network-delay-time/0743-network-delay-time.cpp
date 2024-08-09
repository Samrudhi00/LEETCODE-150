
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      
        vector<pair<int, int>> adj[n + 1];
        for (auto& time : times) {
            adj[time[0]].emplace_back(time[1], time[2]);
        }
       
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
       
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
       
        pq.emplace(0, k);
        
        while (!pq.empty()) {
            int d = pq.top().first; 
            int node = pq.top().second; 
            pq.pop();
            
         
            if (d > dist[node]) continue;
            
            for (auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int time = neighbor.second;
                
                if (dist[node] + time < dist[nextNode]) {
                    dist[nextNode] = dist[node] + time;
                    pq.emplace(dist[nextNode], nextNode);
                }
            }
        }
        
        int mx=0;
        for(int i=1;i<=n;i++){
            if(dist[i] == INT_MAX)return -1;
            mx = max(mx,dist[i]);
        }
        return mx;
      
    }
};
