class Solution
{
    public:
        long long int func(int ind, vector<int> &coins, int sum, vector<vector < int long long>> &dp)
        {
            if (sum == 0)
            {
                return 1;
            }
            if (ind == 0)
            {
                if (sum % coins[0] == 0) return 1;
                else return 0;
            }
            if (dp[ind][sum] != -1) return dp[ind][sum];
            int long long dont = func(ind - 1, coins, sum, dp);
            int long long take = 0;
            if (coins[ind] <= sum)
            {
                take = func(ind, coins, sum - coins[ind], dp);
            }
            return dp[ind][sum] = dont + take;
        }
    int change(int sum, vector<int> &coins)
    {
        int N = coins.size();
        vector<vector < int long long>> dp(N, vector < int long long > (sum + 1, -1));
        return func(N - 1, coins, sum, dp);
    }
};