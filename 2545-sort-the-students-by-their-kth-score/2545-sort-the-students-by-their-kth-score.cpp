class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<vector<int>> ans;
        set<pair<int,int>> st;
        for(int i=0;i<score.size();i++){
            st.insert({score[i][k],i});
        }
        for(auto it: st){
            ans.push_back(score[it.second]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};