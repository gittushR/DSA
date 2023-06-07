class Solution {
public:  
    int cntPath(int i, int j,vector<vector<int>>&dp){
        if(i < 0 or j < 0) return 0;
        if(i == 0 and j == 0) return dp[0][0]= 1;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=cntPath(i-1, j,dp) + cntPath(i, j-1,dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return cntPath(m-1, n-1,dp);
    }
};