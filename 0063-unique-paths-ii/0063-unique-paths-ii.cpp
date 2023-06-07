
class Solution {
public:  
    int cntPath(int i, int j,vector<vector<int>>&dp,vector<vector<int>>& grid){
        if(i < 0 or j < 0) return 0;
        if(grid[i][j]==1)return 0;
        if(i == 0 and j == 0) return dp[0][0]= 1;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=cntPath(i-1, j,dp,grid) + cntPath(i, j-1,dp,grid);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return cntPath(m-1, n-1,dp,grid);
    }
};