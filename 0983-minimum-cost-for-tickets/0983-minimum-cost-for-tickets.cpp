class Solution {
public:
    int solve(int x,vector<int>&days,vector<int>&costs,vector<int>&dp){
        if(x>365)return 0;
        if(dp[x]!=-1)return dp[x];
        int y=lower_bound(days.begin(),days.end(),x)-days.begin();
        if(y==days.size())return 0;
        int d1cost=costs[0];
        if(days[y]!=x)       
            d1cost=0; 
        int d1=d1cost+solve(x+1,days,costs,dp);
        int d2=costs[1]+solve(x+7,days,costs,dp);
        int d3=costs[2]+solve(x+30,days,costs,dp);
        return dp[x]=min(d1,min(d2,d3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(366,-1);

        return solve(1,days,costs,dp);
        
    }
};