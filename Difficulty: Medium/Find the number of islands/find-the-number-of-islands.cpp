//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void bfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int rowInd, int colInd){
        vis[rowInd][colInd]=1;
        queue<pair<int,int>> q;
        q.push({rowInd,colInd});
        int n=grid.size(),m=grid[0].size();
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
            int dRow[8]={-1,-1,-1,0,1,1,1,0};
            int dCol[8]={-1,0,1,1,1,0,-1,-1};
            for(int i=0;i<8;i++){
                int nrow = row + dRow[i];
                int ncol = col + dCol[i];
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m 
                and !vis[nrow][ncol] and grid[nrow][ncol]=='1'){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 and grid[i][j]=='1'){
                    bfs(grid,vis,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends