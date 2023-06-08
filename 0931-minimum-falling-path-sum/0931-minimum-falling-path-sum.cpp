class Solution
{
    public:
        int minFallingPathSum(vector<vector < int>> &matrix)
        {

            int n = matrix.size();

            int m = matrix[0].size();

            vector<vector < int>> dp(n, vector<int> (m, 0));

            for (int j = 0; j < m; j++)
            {
                dp[0][j] = matrix[0][j];
            }

            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    int ld = 1e9, rd = 1e9;

                    int up = matrix[i][j] + dp[i - 1][j];

                    if (j - 1 >= 0)
                        ld = matrix[i][j] + dp[i - 1][j - 1];
                    if (j + 1 < m)
                        rd = matrix[i][j] + dp[i - 1][j + 1];

                    dp[i][j] = min(up, min(ld, rd));
                }
            }

            int mini = dp[n - 1][0];

            for (int j = 1; j < m; j++)
            {

                mini = min(mini, dp[n - 1][j]);
            }
            return mini;
        }
};
/*
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(j>=matrix.size() or j < 0)return 1e9;
        if(i==0)return dp[0][j]=matrix[0][j];
        if(dp[i][j]!=-1)return dp[i][j];

        int up=matrix[i][j]+f(i-1,j,matrix,dp);

        int diagl=matrix[i][j]+f(i-1,j-1,matrix,dp);

        int diagr=matrix[i][j]+f(i-1,j+1,matrix,dp);

        return dp[i][j]=min(up,min(diagl,diagr));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int maxi=INT_MAX;
        vector<vector < int>> dp(n,vector < int>(n,-1));
        for(int a=0;a < n;a++){
            maxi=min(maxi,f(n-1,a,matrix,dp));
        }
        return maxi;
    }
};
*/