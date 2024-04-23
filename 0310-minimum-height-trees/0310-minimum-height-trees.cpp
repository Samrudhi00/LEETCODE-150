class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
        return {0};

        //Adjacency list
        vector<vector<int>> Adj(n);
        for(auto x:edges)
        {
            Adj[x[0]].push_back(x[1]);
            Adj[x[1]].push_back(x[0]);
        }

        //Answer
        vector<int> res;

        //Cardinal number of each node or vertex
        vector<int> card(n);
        for(int i=0;i<n;i++)
        card[i]=Adj[i].size();

        queue<int> q;
        for(int i=0;i<n;i++)    //Start with the end nodes.
        if(card[i]==1)
        q.push(i);

        int grsize=n;           //size of the graph
        while(grsize>2)
        {
            int size=q.size();
            while(size--)
            {
                int cur=q.front();
                for(auto x:Adj[cur])
                {
                    if(card[x])     //cardinality 0 implies that it has been already pruned
                    {
                        card[x]--;      //reduce the cardinality of the adjacent one 
                        card[cur]--;    //to prune the current node

                        if(card[x]==1)  //cardinality 1 implies that  
                        q.push(x);      //it will be an end node at the next
                                        //iteration. So add it to the queue
                    }
                }
                q.pop();
                grsize--;               //reduce the graph size by one
            }
        }
        while(!q.empty())
        {res.push_back(q.front());
        q.pop();}
        return res;
    }
};