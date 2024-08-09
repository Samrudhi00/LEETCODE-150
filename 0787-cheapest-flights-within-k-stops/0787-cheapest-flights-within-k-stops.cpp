class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Adjacency list representation
        vector<pair<int, int>> adj[n];

        // Building the adjacency list
        for (int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        // Priority queue to store {cost, {current node, number of stops}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.push({0, {src, 0}});

        // Distance array to store the minimum cost to reach each node with a certain number of stops
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        // BFS with priority queue
        while (!q.empty()) {
            int cost = q.top().first;
            int node = q.top().second.first;
            int stops = q.top().second.second;
            q.pop();

            // If the destination is reached
            if (node == dst) return cost;

            // If the number of stops exceeds the limit, skip this path
            if (stops > k) continue;

            // Explore the neighbors
            for (auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int nextCost = neighbor.second;

                // If the current path offers a cheaper cost with one more stop, consider it
                if (cost + nextCost < dist[nextNode][stops + 1]) {
                    dist[nextNode][stops + 1] = cost + nextCost;
                    q.push({dist[nextNode][stops + 1], {nextNode, stops + 1}});
                }
            }
        }

        // If no valid route is found
        return -1;
    }
};
