class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        
        int rsum=0;
        for(int i=0;i<=n;i++){
            dp[i][0]=rsum;
            rsum+=s1[i];
        }
        
        int csum=0;
        for(int i=0;i<=m;i++){
            dp[0][i]=csum;
            csum+=s2[i];
        }
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(s1[ind1-1]==s2[ind2-1])dp[ind1][ind2]=dp[ind1-1][ind2-1];
                else dp[ind1][ind2]=min(dp[ind1-1][ind2]+s1[ind1-1],dp[ind1][ind2-1]+s2[ind2-1]);
            }
        }
        return dp[n][m];
    }
};