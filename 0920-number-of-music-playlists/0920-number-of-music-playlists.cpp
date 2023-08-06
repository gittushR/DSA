#define ll long long
#define mod 1000000007
class Solution {
public:
    int n , l, k;
    ll solve(int len , int num,vector<vector<int>> &dp){
        if(len==l)return num==n;
        if(dp[len][num]!=-1)return dp[len][num];
        ll ans= (solve(len+1,num,dp)* max(0,num-k)) % mod;
        ans+=(solve(len+1,num+1,dp)*(n-num))%mod;
        ans=ans%mod;
        return dp[len][num]=ans;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        this-> n=n;
        this->l=goal;
        this->k=k;
        vector<vector<int>> dp(109,vector<int>(109,-1));
        return solve(0,0,dp);
    }
};