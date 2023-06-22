class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int x=s1.size();
        int y=s2.size();
        vector<vector<int>> dp(x+1,vector<int>(y+1,-1));
        for(int i=0;i<=x;i++)dp[i][0]=0;
        for(int j=0;j<=y;j++)dp[0][j]=0;
        
        for(int ind1=1;ind1<=x;ind1++){
            for(int ind2=1;ind2<=y;ind2++){
                if(s1[ind1-1]==s2[ind2-1]) dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                else dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
        return dp[x][y];
    }
};