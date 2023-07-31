class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        
        int r=0;
        for(int i=0;i<=n;i++){
            dp[i][0]=r;
            r++;
        }
        r=0;
        for(int i=0;i<=m;i++){
            dp[0][i]=r;
            r++;
        }
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(word1[ind1-1]==word2[ind2-1])dp[ind1][ind2]=dp[ind1-1][ind2-1];
                else dp[ind1][ind2]=min(dp[ind1-1][ind2]+1,dp[ind1][ind2-1]+1);
            }          
        }
        return dp[n][m];
    }
};