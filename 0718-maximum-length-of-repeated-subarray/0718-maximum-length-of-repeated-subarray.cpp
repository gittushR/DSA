class Solution {
public:
    int findLength(vector<int>& s1, vector<int>& s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int j=0;j<=m;j++)dp[0][j]=0;
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(s1[ind1-1]==s2[ind2-1])dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                else dp[ind1][ind2]=0;
            }
        }
        int ans=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};