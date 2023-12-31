class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       unordered_map<int,int>mp;

       for(auto num:arr){
           mp[num]++;
       } 
       unordered_set<int>set;
        
        for(auto it:mp){
            int freq = it.second;
            set.insert(freq);
        }

       return set.size()==mp.size();
    }
};