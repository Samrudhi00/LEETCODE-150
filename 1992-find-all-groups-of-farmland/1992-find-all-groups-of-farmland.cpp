class Solution {
public:
    pair<int,int> finden(int r,int c,vector<vector<int>>& land)
    {
        int er=r;
        int ec=c;
        while(er<land.size() && land[er][ec]==1) er++;
        while(ec<land[0].size() && land[er-1][ec]==1 ) ec++;
        return {er-1,ec-1};
    }
    void mark(int sr,int sc,int er,int ec,vector<vector<int>>& vis)
    {
        for(int i=sr;i<=er;i++)
        {
            for(int j=sc;j<=ec;j++)
            {
                vis[i][j]=1;
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> ans;
        int n=land.size();
        int m=land[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(land[i][j]==1 && vis[i][j]==0)
                {
                    int sr=i,sc=j;
                    pair<int,int> en=finden(i,j,land);
                    int er=en.first,ec=en.second;
                    vector<int> a1={sr,sc,er,ec};
                    ans.push_back(a1);
                    mark(sr,sc,er,ec,vis);
                }
            }
        }
        return ans;
    }
};