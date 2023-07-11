class Solution {
public:
    int fn(int ind,vector<int> cost,int n,vector<int> &dp){
        if(ind==n)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int oneStep=cost[ind]+fn(ind+1,cost,n,dp);
        int twoStep=1e9;
        if(ind<n-1)twoStep=cost[ind]+fn(ind+2,cost,n,dp);
        return dp[ind]=min(oneStep,twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {\
        vector<int> dp(cost.size()+1,-1);
        int zero=fn(0,cost,cost.size(),dp);
        int one=fn(1,cost,cost.size(),dp);
        return min(one, zero);
    }
};