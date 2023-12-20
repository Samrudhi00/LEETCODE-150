class Solution {
public:
    bool isAnagram(string s, string t) {
    //    int n=s.length();
    //    int m=t.length();
    //    if(n != m) return false;

    //    unordered_map<char,int>mp;
    //    for(auto a:s){
    //        mp[a]++;
    //    }
    //    for(auto a:t){
    //        mp[a]--;
    //    }
    //    for(auto a:mp){
    //        if(a.second !=0) return false;
    //    }
    //    return true;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
        return (s == t);
       

    }
};