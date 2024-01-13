class Solution {
public:
    int minSteps(string s, string t) {
        // vector<int> cnt1(26,0),cnt2(26,0);
        // int i,ans=0;
        // for(i=0;i<s.length();i++){
        //      cnt1[s[i]-'a']++;
        // }
        // for(i=0;i<t.length();i++){
        //      cnt2[t[i]-'a']++;
        // }
        // for(i=0;i<26;i++){
        //     //ans += cnt1[i]-cnt2[i];
        //     if(cnt1[i]>cnt2[i]){
        //         ans+=cnt1[i]-cnt2[i];
        //     }
        // }
        // return ans;

        int cnt=0;
        unordered_map<char,int> mp;
        for(auto x:s)mp[x]++;
        for(auto x:t)mp[x]--;
        for(auto[first,second]:mp){
            if(s<0) cnt+=s;
        }
        return abs(cnt);

    }
};