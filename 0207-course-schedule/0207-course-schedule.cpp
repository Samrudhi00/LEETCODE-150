class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        // Construct adjacency list and calculate indegree
        for(auto& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int prereq = prerequisite[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        
        // Perform topological sort using BFS
        queue<int> q;
        for(int i = 0; i < numCourses; ++i) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        int cnt = 0; // Counter to track the number of visited courses
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            cnt++;
            
            for(int neighbor : adj[curr]) {
                if(--indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        
        // If all courses are visited, return true, else return false
        return cnt == numCourses;
    }
};
