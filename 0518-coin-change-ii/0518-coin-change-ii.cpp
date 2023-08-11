class Solution {
private:
    int helper(int ind,int sum,vector<int> coins,vector<vector<int>> &dp){
        if(sum==0)return 1;
        if(ind==0){
            if(sum%coins[0]==0)return 1;
            return 0;
        }
        if(dp[ind][sum]!=-1)return dp[ind][sum]; 
        int notTake = helper(ind-1,sum,coins,dp);
        int take=0;
        if(coins[ind]<=sum){
            take=helper(ind,sum-coins[ind],coins,dp);
        }
        return dp[ind][sum]=take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return helper(n-1,amount,coins,dp);
    }
};