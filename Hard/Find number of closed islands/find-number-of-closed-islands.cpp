//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void bfs(queue<pair<int,int>> &q,vector<vector<int>>& matrix, int n, int m,vector<vector<int>>& vis){
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, +0, -1}; 
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.first;
            int c=it.second;
            
            for(int i=0;i<4;i++){
                int nr=r+delrow[i];
                int nc=c+delcol[i];
                if(nr>=0 and nc>=0 and nr<n and nc<m 
                and !vis[nr][nc] and matrix[nr][nc]==1){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
    int closedIslands(vector<vector<int>>& matrix, int n, int m) {
        // Code here
        queue<pair<int,int>> q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                // first row, first col, last row, last col 
                if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                    if(matrix[i][j] == 1) {
                        q.push({i, j}); 
                        vis[i][j] = 1; 
                    }
                }
            }
        }
        
        bfs(q,matrix,n,m,vis);
        
        int count=0;
        for(int i=1;i<=n-1;i++){
            for(int j=1;j<=m-1;j++){
                if(matrix[i][j]==1 and !vis[i][j]){
                    count++;
                    q.push({i,j});
                    bfs(q,matrix,n,m,vis);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends