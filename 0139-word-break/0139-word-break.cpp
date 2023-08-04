class Solution {
public:
    map<int,bool> mp;
    bool helper(int ind, string s, unordered_set<string> st){
        if(ind==s.size())return true;
        if(mp.find(ind)!=mp.end())return mp[ind];
        for(int i=ind;i<s.size();i++){
            string temp=s.substr(ind,i-ind+1);
            if(st.find(temp)!=st.end()){
                if(helper(i+1,s,st))return mp[ind]=true;
            }
        }
        return mp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& v) {
        unordered_set<string>st(v.begin(),v.end());
        return helper(0,s,st);
    }
};