class Solution {
public:
    map<int,vector<int>> mp;
    int mod = 1e9+7;
    int helper(int n, int ind, char prev,vector<vector<long long>> &dp){
        if(ind>=n)return 0;
        if(ind==n-1){
            switch(prev){
                case 'a':
                    return 1;
                case 'e':
                    return 2;
                case 'i':
                    return 4;
                case 'o':
                    return 2;
                case 'u':
                    return 1;
                default:
                    return 5;
            }
        }
        int idx=prev -'a';
        if(dp[ind][idx]!=-1)return dp[ind][idx];
        long long ans=0;
        for(auto next:mp[prev]){
            ans+=(helper(n,ind+1,next,dp)%mod);
        }
        return dp[ind][idx]=ans%mod;
    }
    int countVowelPermutation(int n) {
        mp['c']={'a','e','i','o','u'};
        mp['a']={'e'};
        mp['e']={'a','i'};
        mp['i']={'a','e','o','u'};
        mp['o']={'i','u'};
        mp['u']={'a'};
        
        vector<vector<long long>> dp(n+1,vector<long long>(27,-1));
        return helper(n,0,'c',dp);
    }
};