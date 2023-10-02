class Solution {
public:
    int distinctSubseqII(string s) {
        int mod=1000000007;
        int n=s.size();
        vector<int> dp(n+1);
        unordered_map<char,int> mp;
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]=(dp[i-1]*2)%mod;
            char curr=s[i-1];
            if(mp.find(curr)!=mp.end()){
                dp[i]=dp[i]-dp[mp[curr]-1];
            }
            if(dp[i]<0)dp[i]+=mod;
            dp[i]=dp[i]%mod;
            mp[curr]=i;
        }
        if(dp[n]==0)return mod-1; 
        return dp[n]-1;
    }
};