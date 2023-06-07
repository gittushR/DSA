class Solution {
public:
    int f(int i, int j,vector<vector<int>>& grid,vector<vector<long long>> &dp){
        
        if(i==0 && j==0)return dp[0][0]=grid[i][j];
        if(i<0 or j<0)return 1e9;
        long long up=grid[i][j]+f(i-1,j,grid,dp);
        if(dp[i][j]!=-1)return dp[i][j];
        long long left=grid[i][j]+f(i,j-1,grid,dp);
        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<long long>> dp(m,vector<long long>(n,-1));
        return f(m-1,n-1,grid,dp);
    }
};