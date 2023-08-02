//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> grid, int x, int y) {
        if(grid[0][0]==0)return -1;
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        int srow=0;
        int scol=0;
        q.push({0,{srow,scol}});
        dist[srow][scol]=0;
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        
        while(!q.empty()){
            int distance=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            if(row==x and col==y)return distance;
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and 
                distance+1<dist[nrow][ncol] and grid[nrow][ncol]==1){
                    dist[nrow][ncol]=distance+1;
                    q.push({distance+1,{nrow,ncol}});
                    
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends