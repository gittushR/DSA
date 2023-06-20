class Solution
{
    public:
        int findTargetSumWays(vector<int> &A, int target)
        {
            int n = A.size();
            int totalsum = 0;

            for (int i = 0; i < n; i++)
            {
                totalsum += A[i];
            }

            if (totalsum - target < 0 || (totalsum - target) % 2 == 1) return 0;
            int sum = (totalsum - target) / 2;

            vector<vector < int>> dp(n + 1, vector<int> (sum + 1));

            for (int i = 0; i < sum + 1; i++)
            {
                dp[0][i] = 0;
            }

            dp[0][0] = 1;

            for (int i = 1; i < n + 1; i++)
            {
                for (int j = 0; j < sum + 1; j++)
                {
                    if (A[i - 1] <= j)
                    {
                        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - A[i - 1]];
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
            return dp[n][sum];
        }
};