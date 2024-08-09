class Compare {
public:
    bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
    {
        if (a.second.second <= b.second.second) {
            return false;
        }

        return true;
    }
};
class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,int k) {
        vector<pair<int, int>> adj[n];

        for (int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>, Compare> q;
        q.push({0, {src, 0}});

        vector<int> dist(n,INT_MAX);
        dist[src] = 0;

        while (!q.empty()) {
            int cost = q.top().first;
            int node = q.top().second.first;
            int stops = q.top().second.second;
            q.pop();

            if (stops > k) continue;

            for (auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int nextCost = neighbor.second;

                if (cost + nextCost < dist[nextNode]) {
                    dist[nextNode] = cost + nextCost;
                    q.push({dist[nextNode], {nextNode, stops + 1}});
                }
            }
        }

        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};