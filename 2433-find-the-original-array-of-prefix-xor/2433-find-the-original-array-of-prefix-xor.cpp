class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int a=0;
        vector<int> ans;
        for(int i=0;i<pref.size();i++){
            ans.push_back(a^pref[i]);
            a=pref[i];
        }
        return ans;
    }
};