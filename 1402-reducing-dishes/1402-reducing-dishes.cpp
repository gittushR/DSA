class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>&a,int n,int mul)
    {
        if(n>=a.size())
        {
            return 0;
        }
        if(dp[n][mul]!=INT_MIN)
        {
            return dp[n][mul];
        }
        return dp[n][mul]=max(a[n]*mul+solve(a,n+1,mul+1),solve(a,n+1,mul));
    }
    int maxSatisfaction(vector<int>& satisfaction)
    {
        dp.resize(501 ,vector<int> (501, INT_MIN));
        sort(satisfaction.begin(),satisfaction.end());
        int ans=solve(satisfaction,0,1);
        
        return ans;
    }
};