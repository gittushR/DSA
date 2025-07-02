// User function template for C++
class Solution {
  public:
    string removeDuplicates(string &s) {
        // code here
        unordered_map<char,int> mp;
        string ans="";
        for(auto it: s){
            if(mp.find(it)==mp.end()){
                ans+=it;
                mp[it]++;
            }
        }
        return ans;
    }
};