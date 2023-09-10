class Solution {
public:
    const int MOD = 1e9 + 7;
    int countOrders(int n) {
        if(n==1)return 1;
        long long prev,curr;
        prev=1;
        for(int i=2;i<=n;i++){
            int maxNum= 2*i-1;
            int permutations= maxNum * (maxNum+1)/2;
            curr=(prev*permutations) % MOD;
            prev=curr;
        }
        return prev;
    }
};