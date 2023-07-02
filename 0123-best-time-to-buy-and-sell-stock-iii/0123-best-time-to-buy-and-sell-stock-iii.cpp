class Solution
{
    public:
        // int fn(int ind, int buy, int cap, vector<int> prices, int n, vector<vector< vector< int>>> &dp)
        // {
        //     if (ind == n) return 0;
        //     if (cap == 0) return 0;
        //     if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        //     int profit = 0;
        //     if (buy)
        //     {
        //         profit = max(-prices[ind] + fn(ind + 1, 0, cap, prices, n, dp), fn(ind + 1, 1, cap, prices, n, dp));
        //     }
        //     else
        //     {
        //         profit = max(prices[ind] + fn(ind + 1, 1, cap - 1, prices, n, dp), fn(ind + 1, 0, cap, prices, n, dp));
        //     }
        //     return dp[ind][buy][cap] = profit;
        // }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int dp[n+1][2][3];
        for(int i=0;i<=n;i++){
            for(int j=0;j<2;j++){
              for(int k=0;k<3;k++){
                  dp[i][j][k]=0;
              }  
            }
        }
        for (int i = 0; i < 3; i++)
        {
            dp[n][0][i] = dp[n][1][i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                dp[i][j][0] = 0;
            }
        }
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                for (int cap = 1; cap < 3; cap++)
                {
                    int profit=0;
                    if (buy)
                    {
                        profit = max(-prices[ind] + dp[ind + 1][0][cap], dp[ind+1][1][cap]);
                    }
                    else
                    {
                        profit = max(prices[ind] + dp[ind + 1] [1] [cap - 1], dp[ind + 1] [0] [cap]);
                    }
                    dp[ind][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};