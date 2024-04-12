class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n =score.size();
        vector<string>ans(n);
        map<int,int>mp;
        for(int i=0; i<score.size(); i++){
            mp[score[i]] = i;
        }
        priority_queue<int>pq(score.begin(), score.end());
        int cnt = 1;
        while(!pq.empty()){
            int mx = pq.top(); pq.pop();
            if(cnt == 1) ans[mp[mx]] = "Gold Medal";
            else if(cnt == 2) ans[mp[mx]] = "Silver Medal";
            else if(cnt == 3) ans[mp[mx]] = "Bronze Medal";
            else{
                ans[mp[mx]] = to_string(cnt);
            }
            cnt++;
        }
        return ans;
    }
};