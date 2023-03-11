class Solution {
public: 
    bool allStars(string & s, int i) {
        for (int j = 0; j <= i; j++) {
            if (s[j] != '*')
            return false;
        }
        return true;
    }
    bool f(int i,int j,string s1,string s2,vector<vector<bool>>& dp){
        if(i<0 && j<0)  return true;
        if(j<0 && i>=0)  return false; 
        if(i<0 && j>=0)
            return allStars(s2,j); 
        if(dp[i][j]!=-1)  return dp[i][j]; 

        if(s1[i]==s2[j] || s2[j]=='?'){
            return dp[i][j]=f(i-1,j-1,s1,s2,dp); 
        }
        else{
            if(s2[j]=='*'){
                return f(i-1,j,s1,s2,dp) || f(i,j-1,s1,s2,dp); 
            }
            else{
                return false; 
            }
        }
    }
    bool isMatch(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false)); 
        dp[0][0]=true; 
        for(int i=1;i<=n;i++){
            dp[i][0]=false; 
        }
        for(int j=1;j<=m;j++){
            dp[0][j]=allStars(s2,j-1); 
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1] || s2[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1]; 
                }
                else{
                    if(s2[j-1]=='*'){
                        dp[i][j]=dp[i-1][j] ||dp[i][j-1]; 
                    }
                    else{
                        dp[i][j]=false; 
                    }
                }
            }
        }
        return dp[n][m]; 
    }
};