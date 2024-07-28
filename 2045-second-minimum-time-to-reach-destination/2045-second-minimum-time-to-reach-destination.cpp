class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        int r = edges.size();
        int c = edges[0].size();

        vector<int> adj[n + 1];
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int res = -1;

        queue<pair<int, int>> q;
        q.push({0, 1});
        vector<int> visit[n + 1]; 
        vector<vector<int>> times(n + 1);
        while (!q.empty()) {
            auto [t, u] = q.front();
            q.pop();

            if (u == n) {
                if (res == -1) { 
                    res = t;
                } else if (res < t)
                    return t;
            }
            if ((t / change) % 2 == 1) {     
                t += (change - (t % change)); 
            }
            t += time;
            for (auto& it : adj[u]) {

                if (times[it].size() == 0 ||
                    (times[it].size() == 1 && times[it][0] != t)) {
                    q.push({t, it});
                    times[it].push_back(t);
                }
            }
        }

        return -1;
    }
};