class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto it:s)mp[it]++;
        vector<pair<int,char>> vec;
        for(auto it:mp)vec.push_back({it.second,it.first});
        sort(vec.begin(),vec.end());
        string ans="";
        for(int i=0;i<vec.size();i++){
            int j=vec[i].first;
            while(j--){
                ans+=vec[i].second;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};