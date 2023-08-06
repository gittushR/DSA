class Solution {
    int minDis(vector<pair<int, int>> &cord, int i, int j){
        int dist = INT_MAX;
        for(auto &it : cord){
            dist = min(dist, abs(i-it.first)+abs(j-it.second));
        }
        return dist;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 or grid[n-1][n-1]==1) return 0;
        priority_queue<pair<int, pair<int ,int>>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vector<pair<int, int>> cord;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) cord.push_back({i, j});
            }
        }
        int ans=minDis(cord, 0, 0);
        q.push({ans, {0, 0}});
        while(!q.empty()){
            int i = q.top().second.first;
            int j = q.top().second.second;
            ans = min(ans, q.top().first);
            if(i==n-1 and j==n-1){
                return ans;
            }
            q.pop();
            int dir[] = {-1, 0, 1, 0, -1};
            for(int p=0; p<4; p++){
                int ii = i+dir[p];
                int jj = j+dir[p+1];
                if(ii>=0 and jj>=0 and ii<n and jj<n and !vis[ii][jj] and grid[ii][jj]==0){
                    vis[ii][jj]=true;
                    int dist = minDis(cord, ii, jj);
                    q.push({dist, {ii, jj}});
                }
            }
        }
        return 0;
    }
};