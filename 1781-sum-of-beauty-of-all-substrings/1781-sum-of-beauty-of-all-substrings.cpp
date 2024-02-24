class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.size()-1;i++){
            unordered_map<char,int>mpp;
            mpp[s[i]]++;
            for(int j=i+1;j<s.size();j++){
                mpp[s[j]]++;
                int maxi=INT_MIN;
                int mini=INT_MAX;
                for(auto x:mpp){
                    maxi=max(x.second,maxi);
                    mini=min(x.second,mini);
                }
                ans=ans+maxi-mini;
            }
        }
        return ans;
    }
};