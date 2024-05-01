class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int suma=0,sumb=0;
        unordered_map<int,int> mp;
        for(auto x:aliceSizes)
            suma+=x;
        for(auto x:bobSizes)
            {
                sumb+=x;
                mp[x]=1;
            }
        int diff=((suma-sumb)/2);
        for(auto x:aliceSizes)
        {
            if(mp[x-diff]==1)
                return {x,x-diff};
        }
        return {0,0};
    }
};