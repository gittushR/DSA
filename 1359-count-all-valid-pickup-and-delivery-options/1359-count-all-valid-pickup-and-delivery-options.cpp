class Solution {
public:
    const int MOD = 1e9 + 7;
    int countOrders(int n) {
        long long dp[501]={0};
        dp[1]=1*1ll;
        dp[2]=6*1ll;
        for(int i=3;i<=n;i++){
            int maxNum= 2*i-1;
            int permutations= maxNum * (maxNum+1)/2;
            dp[i]=(dp[i-1]*permutations) % MOD;
        }
        return dp[n];
    }
};