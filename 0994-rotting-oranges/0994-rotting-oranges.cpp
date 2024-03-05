class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        int countFresh=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }else if(grid[i][j]==1){
                    countFresh++;
                    vis[i][j]=1;
                }
            }
        }
        int tm=0;
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.first.first;
            int c=it.first.second;
            int t=it.second;
            tm=max(t,tm);
            for(int i=0;i<4;i++){
                int dr=r+drow[i];
                int dc=c+dcol[i];
                if(dr>=0 and dr<m and dc>=0 and dc<n and vis[dr][dc]!=2 and grid[dr][dc]==1){
                    vis[dr][dc]=2;
                    q.push({{dr,dc},t+1});
                    countFresh--;
                }
            }
        }
        if(countFresh!=0)return -1;
        return tm;
    }
};