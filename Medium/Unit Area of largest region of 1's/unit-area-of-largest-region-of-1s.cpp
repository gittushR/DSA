//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int bfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid){

    int n = grid.size();
    int m = grid[0].size();
    int cnt = 1;

    queue<pair<int,int>> q;

    q.push({row, col});
    vis[row][col] = 1;
    
    int delRow[8]={-1,-1,0,1,1,1,0,-1};
    int delCol[8]={0,1,1,1,0,-1,-1,-1};

    while(!q.empty()){

        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i=0; i<8; i++){
            int newRow=row+delRow[i];
            int newCol=col+delCol[i];

            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && !vis[newRow][newCol]
                && grid[newRow][newCol]==1){
                cnt++;
                vis[newRow][newCol] = 1;
                q.push({newRow,newCol});

            }
        }
    }
    return cnt;
 }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        
        int res = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    int count = bfs(i, j, vis, grid);
                    res = max(count, res);
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends