class Solution {
public:
    int mod = (int) 1e9 + 7;
    int fn(int ind, int end, int k,vector<vector<int>>&dp){
        if(k==0){
            if(ind==end)return 1;
            else return 0;
        }
        if(dp[ind+1000][k]!=-1)return dp[ind+1000][k];
        int left=fn(ind-1,end,k-1,dp)%mod;
        int right=fn(ind+1,end,k-1,dp)%mod;
        return dp[ind+1000][k]=(left+right)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3005,vector<int>(k+1,-1)); 
        return fn(startPos,endPos,k,dp);
    }
};