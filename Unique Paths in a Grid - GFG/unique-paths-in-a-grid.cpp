//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  long long mod=(1e9+7);
    long long f(int i, int j,vector<vector<long long>>&dp,vector<vector<int>> &grid){
        if(i==0 and j==0)return 1;
        if(i<0 or j<0)return 0;
        if(grid[i][j]==0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        long long up=f(i,j-1,dp,grid);
        long long left=f(i-1,j,dp,grid);
        return dp[i][j]=(up+left)%mod;
    }
    int uniquePaths(int a, int b, vector<vector<int>> &grid) {
        // code here
        if(grid[0][0]==0)return 0;
        vector<vector<long long>>dp(a,vector<long long>(b,-1));
        return f(a-1,b-1,dp,grid);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends