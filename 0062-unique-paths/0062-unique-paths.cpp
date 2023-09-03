class Solution {
public:
    int paths(int x , int y,vector<vector<int>>&dp){
        if(x==0 and y==0)return 1;
        if(x<0 or y<0)return 0;
        if(dp[x][y]!=-1)return dp[x][y];
        int left=paths(x,y-1,dp);
        int right=paths(x-1,y,dp);
        return dp[x][y]=left+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return paths(m-1,n-1,dp);
    }
};