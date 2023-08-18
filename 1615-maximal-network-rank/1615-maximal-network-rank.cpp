class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        set<pair<int, int>> st;
        vector<int> inDeg(n, 0);
        for(auto &it : roads){
            st.insert({min(it[0], it[1]), max(it[0], it[1])});
            inDeg[it[0]]++;
            inDeg[it[1]]++;
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(st.find({i, j})!=st.end()){
                    ans=max(ans, inDeg[i]+inDeg[j]-1);
                }
                else{
                    ans=max(ans, inDeg[i]+inDeg[j]);
                }
            }
        }
        return ans;
    }
};