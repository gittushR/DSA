class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mp;
        string ans="";

        for(auto i:s)mp[i]++;

        for(auto i:order){
            if(mp.find(i)!= mp.end()){
                while(mp[i]){
                    ans+=i;
                    mp[i]--;
                }
            }
        }

        for(auto i:s)
            if(mp.find(i)==mp.end() || mp[i]>=1)ans+=i;

        return ans;
    }
};