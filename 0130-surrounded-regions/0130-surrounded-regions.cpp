class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>> &grid){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        int delrow[]={0,-1,0,1};
        int delcol[]={-1,0,1,0};
        
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and grid[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,grid);
            }
        }
    }
public:
    void solve(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(grid[0][i]=='O' && !vis[0][i]){
                dfs(0,i,vis,grid);
            }
            
            if(grid[n-1][i]=='O' and !vis[n-1][i]){
                dfs(n-1,i,vis,grid);
            }
        }
        
        for(int i=0;i<n;i++){
            if(grid[i][0]=='O' && !vis[i][0]){
                dfs(i,0,vis,grid);
            }
            
            if(grid[i][m-1]=='O' and !vis[i][m-1]){
                dfs(i,m-1,vis,grid);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='O'){
                    grid[i][j]='X';
                }
            }
        }
    }
};