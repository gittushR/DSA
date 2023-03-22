class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> v[n+1];
        
        for(int i=0;i<roads.size();i++) {
            v[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            v[roads[i][1]].push_back({roads[i][0], roads[i][2]});
            
        }
        vector<int> isVis(n+1,0);
        isVis[1] = 1;
        queue<int> q;
        q.push(1);
        int mini = 1e8;
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0;i<sz;i++) {
                int node = q.front();
                isVis[node] = 1;
                q.pop();
                for(auto it : v[node]) {
                    if(!isVis[it.first]) {
                        q.push(it.first);
                        mini = min(mini, it.second);
                    }
                }
            }
        }

        return mini;
    }
};